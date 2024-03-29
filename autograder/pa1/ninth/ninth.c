#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "ninth.h"

int main(int argc, char **argv) {
	
	
	//file check
	if(access(argv[1], F_OK )==-1) {
		printf("error");
		exit(0);
	}
	
	FILE *f;
	f = fopen(argv[1], "r");

	struct node *root = NULL;
	
//variables for reading in
	char instruction;
	int data;	
	while (fscanf(f, " %c", &instruction)!=EOF) { //takes in the space and the int 
		fscanf(f, " %d", &data);
		//data is now read in
		//printf("instruction %c with data %d \n", instruction, data);
		if (instruction == 'i') { //insert
			if (root==NULL) {
				root = (struct node *)malloc(sizeof(struct node));
				root->leftChild = NULL;
				root->rightChild = NULL;
				root->data = data;
				printf("inserted");
				printf(" %d\n", calcHeight(root, data));
				continue;
				//skip to next instruction
			}
			struct node *ptr = root;
			struct node *prev = root;
			int direction=0;
			while (ptr!=NULL) {
				//check if no tree present
				prev = ptr;
				if (ptr->data < data) {
					ptr = ptr->rightChild;
					direction = 1;
				} else if (ptr->data > data) {
					//printf("1\n");
					ptr = ptr->leftChild;
					//printf("2\n");
					direction = -1;
				} else {
					printf("duplicate\n"); //dont print number here anyways, KEEP NEW LINE
					break; //duplicate value //if code reaches here, then ptr is not NULL so the following if statement will not run
				}
			}
			if (ptr==NULL) {
				//printf("3, direction %d\n", direction);
				ptr = (struct node *)malloc(sizeof(struct node));
				ptr->leftChild = NULL;
				ptr->rightChild = NULL;
				ptr->data = data;
				if (direction == -1) {
					//printf("4\n");
					printf("inserted");
					prev->leftChild = ptr;
					printf(" %d\n", calcHeight(root, data));
				} else if (direction == 1) {
					//printf("5\n");
					printf("inserted");
					prev->rightChild = ptr;					
					printf(" %d\n", calcHeight(root, data));
				} else { //direction == 0
					//printf("6\n");
					printf("ERROR WHY AM I HERE\n");
				}
			}
		} else if (instruction == 's') { //search
			struct node *ptr = root;
			int found = 0;
			while (ptr!=NULL) {
				if (ptr->data < data) { //go to the right
					ptr = ptr->rightChild;
				} else if (ptr->data > data) {
					ptr = ptr->leftChild;
				} else { //found the element
					found = 1;
					printf("present");
					printf(" %d\n", calcHeight(root, data));
					break; //out of this while loop
				}
			}
			if (found == 0) {
				printf("absent\n");
			}
		} else if (instruction == 'd') {
			root = helperDelete(root, data);
		}
	}
	
	freeTree(root);
	return 0;
}



//finds the left most node, used for replacing when deleting
struct node *leftMostNode(struct node *head) {
	struct node *prev = head;
	struct node *ptr = head;
	if (ptr->leftChild == NULL) {
		return ptr;
	}
	while (ptr != NULL) {
		prev = ptr;
		ptr = ptr->leftChild;
	}
	return prev;
}

struct node *helperDelete(struct node *root, int query) {
	check = 0; //not found yet
	struct node *temp =  deleteFromTree(root, query);
	if (check == 0) { //never found
		printf("fail\n");
	}
	return temp; 
}

struct node *deleteFromTree(struct node *root, int query) {
	struct node *ptr = root;
//trivial case
	if (ptr == NULL) {
		return root;
	}
//traversing through tree until value is found
	if (ptr->data == query) {
		//delete the node right here
		if (ptr->leftChild == NULL && ptr->rightChild == NULL) {
			free(ptr);
			check = 1;
			printf("success\n");
			return NULL;
		} else if (ptr->leftChild == NULL) {
			struct node *connect = ptr->rightChild;
			free(ptr);
			check = 1;
			printf("success\n");
			return connect;
		} else if (ptr->rightChild == NULL) {
			struct node *connect = ptr->leftChild;
			free(ptr);
			check = 1;
			printf("success\n");
			return connect;
		} else { //there are two children
			//go to left subtree, find the rightmost node of that subtree
			struct node *replacement = leftMostNode(ptr->rightChild);
			int dataMoved = replacement->data;
			ptr->data = dataMoved;
			ptr->rightChild = deleteFromTree(ptr->rightChild, dataMoved);
			return ptr;
		}
	} else if (ptr->data < query) { //go to the right
		ptr->rightChild = deleteFromTree(ptr->rightChild, query);
	} else if (ptr->data > query) { //go to the left
		ptr->leftChild = deleteFromTree(ptr->leftChild, query);
	}
	return ptr;
}

int calcHeight(struct node *head, int query) {
	// assume the query is in the tree
	if (head == NULL) {
		return 0;
	}
	
	int height=1;
	while (head->data != query) {
		if (head->data > query) {
			head = head->leftChild;
		} else {
			head = head->rightChild;
		}
		height++;
	}
	return height;
}

void freeTree(struct node *head) {
	if (head==NULL) {
		return;
	}
	if (head->leftChild==NULL && head->rightChild==NULL) {
		free(head);
		return;
	}
	freeTree(head->leftChild);
	freeTree(head->rightChild);
}