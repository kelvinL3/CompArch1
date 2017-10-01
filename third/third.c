#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char **argv) {
	
	/*
	
	read in text file name
	
	struct node *array[bucketNumber];
	int i;
	for (i=0;i<bucketNumber;i++) {
		array[i] = NULL;
		array[i] = NULL;
	}
	
	
	while (there is input) {
		struct node *entry;
		scanf("%d", &(node->data));
		find hash value
		keep on checking array at hash value until you see the end of the linked list
		output - insert, duplicate; present, absent
	}
	*/
}

int hash(struct node query, int size){
	return query % size;
}

//1 means inserted, -1 means duplicate
int insert(struct node **array, int position, int insertValue){
	//if there is a null pointer, nothing was there
	if (array[position] == NULL) {
		struct node *ans;
		ans->data = insertValue;
		ans->next = NULL;
		temp = ans;
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
	struct node *ans;
	ans->data = insertValue;
	ans->next = NULL;
	temp->next = ans;
	return 1;
}

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

