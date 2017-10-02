

struct node {
	struct node *leftChild;
	struct node *rightChild;
	int data;
};


struct node *rightMostNode(struct node *head);

struct node *deleteFromTree(struct node *root, int query);