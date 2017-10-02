//globals
int size;

//helper functions
int checkDifferent(int **array);

//helper method for checkDifferent
int exists(int **array, int query);

int checkHorizontalSum(int **array, int same, int size);

int checkVerticalSum(int **array, int same, int size);

int checkDiagonalSum(int **array, int same, int size);

void printMatrix(int **baseArray);