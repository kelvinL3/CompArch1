#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "third.h"

int main(int argc, char **argv) {
	
	if(access(argv[1], F_OK )==-1) {
		printf("error");
		exit(0);
	}
	
	
	// initialize hash table
	struct node **array = (struct node **)malloc(sizeof(struct node *)*bucketNumber);
	int i;
	for (i=0;i<bucketNumber;i++) {
		array[i] = NULL;
	}
	
	
	
	FILE *f;
	f = fopen(argv[1], "r");
	
	char instruction = NULL ;
	int package = NULL;
	while (fscanf(f, " %c", &instruction)!=EOF){
		fscanf(f, " %d", &package);
		//printf("i, #  %c %d\n", instruction, package);
		
		/*struct node *entry = (struct node *)malloc(sizeof(struct node));
		entry->next = NULL;
		entry->data = package;*/
		int temp;
		if (instruction == 'i') {		
			temp = insert(array, hash(package, bucketNumber), package);
			if (temp == 1) {
				printf("inserted\n");
			} else {
				printf("duplicate\n");
			}
		} else if (instruction == 's'){
			temp = search(array, hash(package, bucketNumber), package);
			if (temp == 1) {
				printf("present\n");
			} else {
				printf("absent\n");
			}
		}
	}
	// inserted vs duplicate // present vs absent
	
	freeHashTable(array);
}

int hash(int query, int size){
	return query % size;
}

//1 means inserted, -1 means duplicate
int insert(struct node **array, int position, int insertValue){
	//if there is a null pointer, nothing was there
	if (array[position] == NULL) {
		struct node *ans = (struct node *)malloc(sizeof(struct node));
		ans->data = insertValue;
		ans->next = NULL;
		array[position] = ans;
		return 1;
	}
	//if there wasnt a null pointer, there was something there
	struct node *temp = array[position];
	while (temp->next != NULL) {
		if (temp->data == insertValue) {
			return -1;
		}
		temp=temp->next;
	}
	if (temp->data == insertValue) {
			return -1;
	}
	struct node *ans = (struct node *)malloc(sizeof(struct node));
	ans->data = insertValue;
	ans->next = NULL;
	temp->next = ans;
	return 1;
}

//-1 means absent, 1 means present
int search(struct node **array, int position, int query){
	if (array[position] == NULL) {
		//absent
		return -1;
	}
	struct node *temp = array[position];
	while (temp->next != NULL) {
		if (temp->data == query) {
			return 1;
		}
		temp = temp->next;
	}
	if (temp->data == query) {
		return 1;
	}
	return -1;
}

void freeHashTable(struct node **array){
	int i;
	for (i=0; i<bucketNumber; i++) {
		freeList(array[i]);
	}
	free(array);
	return;
}

void freeList(struct node *head) {
	if (head == NULL) {
		//printf("FLAG1");
		return;
	}
	while(head->next != NULL){
		//printf("FLAG2");
		freeList(head->next);
	}
	free(head);
}