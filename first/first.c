#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "first.h"


int main(int argc, char **argv) {
	printf("argv[1]==%s\n", argv[1]);
	//check if file exists
	if(access(argv[1], F_OK )==-1) {
		printf("error");
		exit(0);
	}
	
	
	FILE *f;
	f = fopen(argv[1], "r");
	
	struct node *head;// = (struct node *) malloc(sizeof(struct node));
	//head->next = NULL;
	//head->data = NULL;
	char instruction = NULL ;
	int package = NULL;
	while (fscanf(f, "%c", &instruction)!=EOF){
		fscanf(f, "%d", &package);
		printf("\ni, #  %c %d\n\n", instruction, package);
		if (instruction == 'i') {
			printf("INSERT\n");
			head = addNode(head, package);
		} else if (instruction == 'd') {
			printf("DELETE\n");
			head = removeNode(head, package);
		}
	}
	
	
	
	printf("THE DIVIDE\n");
	/*
	
	std in
	argc, argv
	argv is a line
	FILE *f;
	f = fopen(argv[1], "r");	
	
	fscanf(file pointer, "%d\t", address) \t means \t is the delimiter
	
	*/
	
	int i = lengthOfList(head);
	
	if (i==0) {
		printf("0\n");
		return 1;
	} else { 
		printf("%d\n",i);
		while (i>1){
			printf("%d\t", head->data);
			head = head->next;
			i--;
		}
		printf("%d", head->data);
	}
	
	lengthOfList(head);
}

struct node *addNode(struct node *head, int newData) {
	//if *head points to NULL, which equals 0 or false; 
	struct node *temp = head;
	struct node *insert;
	//insert->next = NULL;
	//insert->data = newData;
	printf("Mattress 0\n");
	// if there is no list at first, ie if head is NULL
	if (head==NULL) {
		return insert;
	}
	printf("Mattress 1\n");
	// if the new node should go at the beginning
	if (newData < temp->data) {
		insert->next = temp;
		return insert;
	} else if (newData == temp->data) {
		return head;
	}
	
	printf("Mattress 2\n");
	// if the new node should go anywhere else or is a duplicate
	struct node *temp2 = head;
	while (!temp) {
		printf("Mattress 3\n");
		temp2 = temp;
		temp = temp->next;
		if (temp==NULL) {
			break;
		}
		if (newData < temp->data) {
			temp2->next = insert;
			insert->next = temp;
			return head;
		} else if (temp->data == newData) {
			return head;
		}
	}
	printf("Mattress 4\n");
	//check the data of temp2 when it is on the last node
	if (temp2->data < newData) {
		temp2->next = insert;
		// insert->next is still NULL
	}
	
	return head;
}

struct node *removeNode(struct node *head, int deleteData) {
	struct node *ptr1 = head;
	struct node *ptr2 = ptr1->next;
	
	printf("Pillow 1\n");
	//if the first node is deleted
	if (ptr1->data == deleteData) {
		return ptr2; //return NULL
	}
	while (ptr2 != NULL) {
		printf("Pillow 2\n");
		if (ptr2->data == deleteData) {
			ptr1->next = ptr2->next;
			return head;
		}
		ptr1 = ptr1 -> next;
		ptr2 = ptr2 -> next;
	}
	return head;
}

int lengthOfList(struct node *head){
	struct node *temp = head;
	int i=0;
	while(head != NULL){
		head = head->next;
		i++;
	}
	return i;
}
