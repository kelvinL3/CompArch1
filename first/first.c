#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char **argv) {
	
	
	check if file exists
		if not, printf("error") and return
	
	
	//std in
	//argc, argv
	//argv is a line
			
	//
	//fscanf(filename, "%d\t", address) \t means \t is the delimiter
	
	struct node *head;
	head->next = NULL;
	head->data = NULL;
	while (there exists next line){
		parse the first thing as letter
		parse the second thing as data (number)
		if (letter = i) {
			head = addNode(head, data);
		}
		if (letter = i) {
			head = addNode(head, data);
		}
	}
	
	int i = lengthOfList(head);
	printf("%d\n",i);
	if (i==0) {
		return 1;
	} else { 
		while (i>0){
			printf("%d\t", head->data);
			head = head->next;
			i--;
		} 
		printf("%d", head->data);
	}
	
}

struct node *addNode(struct node *head, int newData) {
	//if *head points to NULL, which equals 0 or false; 
	struct node *temp = head;
	struct node *insert;
	insert->next = NULL;
	insert->data = newData;
	
	// if there is no list at first, ie if head is NULL
	if (head==NULL) {
		return insert;
	}
	
	// if the new node should go at the beginning
	if (newData < temp->data) {
		insert->next = temp;
		return insert;
	} else if (newData == temp->data) {
		return head;
	}
	
	// if the new node should go anywhere else or is a duplicate
	struct node *temp2 = head;
	while (!temp) {
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
	//check the value of temp2 when it is on the last node
	if (temp2->value < newData) {
		temp2->next = insert;
		// insert->next is still NULL
	}
	
	return head;
}

struct node *removeNode(struct node *head, int deleteData) {
	struct node *ptr1 = head;
	struct node *ptr2 = ptr1->next;
	
	//if the first node is deleted
	if (ptr1->data == deleteData) {
		return ptr2;
	}
	while (!ptr2) {
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
	while(!head){
		head = head->next;
		i++;
	}
	return i;
}