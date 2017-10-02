//globals and constants


//structs
struct node {
	struct node *next;
	int data;	
};

// inserts the new entry, does nothing if duplicate
// returns head
struct node *addNode(struct node *head, int newData);

// removes the entry, if it is there
// return head;
struct node *removeNode(struct node *head, int deleteData);

//traverses the list to find the length
int lengthOfList(struct node *head);

//utility function
void printList(struct node *head);

//recursively free a malloc-ed linked list
void freeList(struct node *head);