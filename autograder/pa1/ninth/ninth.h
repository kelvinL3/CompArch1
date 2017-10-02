struct node {
	struct node *leftChild;
	struct node *rightChild;
	int data;
};

int check;

struct node *rightMostNode(struct node *head);

struct node *deleteFromTree(struct node *root, int query);

int calcHeight(struct node *head, int query);

void freeTree(struct node *head);