//global
const unsigned int bucketNumber = 10000;


//structs
struct node {
	struct node *next;
	int data;	
}

//functions
//returns modulus
int hash(int query, int size);

//go to position in array, go down linked list until end
int insert(int *array, int position);

//go to position, search through linked list until finding query
int search(int *array, int position, int query);

