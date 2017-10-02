struct node {
	struct node *leftChild;
	struct node *rightChild;
	int data;
};

int check;

struct node *leftMostNode(struct node *head);

struct node *helperDelete(struct node *root, int query);

struct node *deleteFromTree(struct node *root, int query);

int calcHeight(struct node *head, int query);

//int calcHelper(struct node *ptr, int query);

void freeTree(struct node *head);