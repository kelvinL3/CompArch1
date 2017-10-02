//globals
int size;

//helper functions
int checkDifferent(int **array);

//helper method for checkDifferent
int exists(int **array, int query);

int checkHorizontalSum(int **array, int same);

int checkVerticalSum(int **array, int same);

int checkDiagonalSum(int **array, int same);

void printMatrix(int **baseArray);