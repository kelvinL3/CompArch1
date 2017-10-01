#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char **argv) {
	
	//argv is first input, filename?
	
//setting up the binary tree root
	struct node *root = NULL;
	
	int i;
//variables for reading in
	char action;
	int data;
//argv[0] is the file name?
	fscanf(argv[0], "%c\t", &action); //takes in first character
	while (fscanf(argv[0], " %d\n", &data) != EOF) { //takes in the space and the int 
		//do stuff
		
		if (action == 'i') { //insert
			if (root==NULL) {
				root = (struct node *)malloc(sizeof(struct node));
				root->leftChild = NULL;
				root->rightChild = NULL;
				root->data = data;
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
					ptr = ptr->leftChild;
					direction = -1;
				} else {
					break; //duplicate value //if code reaches here, then ptr is not NULL so the following if statement will not run
				}
			}
			if (ptr==NULL) {
				ptr = (struct node *)malloc(sizeof(struct node));
				ptr->leftChild = NULL;
				ptr->rightChild = NULL;
				ptr->data = data;
				if (direction == -1) {
					prev->leftChild = ptr;
				} else if (direction = 1) {
					prev->rightChild = ptr;					
				} else { //direction == 0
					
				}
			}
		} else if (action == 's') { //search
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
					break;
				}
			}
			if (found == 0) {
				printf("absent");
			}
		} else if (action == 'd') {
			
		}
		
		//end do stuff
		fscanf(argv[0], "%c\t", &action);
	}
	
	
	
	//recursively free the nodes with POSTORDER transversal
	return 1;
}



//finds the left most node, used for replacing when deleting
struct node *rightMostNode(struct node *head) {
	struct node *prev = head;
	struct node *ptr = head;
	if (ptr->rightChild == NULL) {
		return ptr;
	}
	while (ptr != NULL) {
		prev = ptr;
		ptr = ptr->rightChild;
	}
	return prev;
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
			return NULL;
		} else if (ptr->leftChild == NULL) {
			struct node *connect = ptr->rightChild;
			free(ptr);
			return connect;
		} else if (ptr->rightChild == NULL) {
			struct node *connect = ptr->leftChild;
			free(ptr);
			return connect;
		} else { //there are two children
			//go to left subtree, find the rightmost node of that subtree
			struct node *replacement = rightMostNode(ptr->leftChild);
			int dataMoved = replacement->data;
			ptr->data = dataMoved;
			ptr->leftChild = deleteFromTree(ptr->leftChild, dataMoved);
			return ptr;
		}
	} else if (ptr->data < query) { //go to the right
		ptr->rightChild = deleteFromTree(ptr->rightChild, query);
	} else if (ptr->data > query) { //go to the left
		ptr->leftChild = deleteFromTree(ptr->leftChild, query);
	}
	printf("Why am I getting here???\n");
	return NULL;
}