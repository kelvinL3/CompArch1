#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char **argv) {
	int size;
	//argv is first input, filename?
	fscanf(argv[1], "%d\t", &size);
	int *array[size] = (int **)malloc(sizeof(int *) * size);
	int i;
	for (i=0; i<size; i++) {
		array[i] = (int *) malloc(sizeof(int) * size);
	}
	int j;
	for (i=0; i<size; i++) {
		for (j=0; j<size; j++) {
			fscanf(argv[0], "%d\t", &array[i][j]);
		}
	}
//sum up the top row, use that as comparison
	int total = 0;
	for (i=0; i<size; i++) {
		total = total + array[i][0];
	}
	if (checkDifferent(array,size)!=1) {
		printf("not-magic");
	} else if (checkHorizontalSum(array,total,size)!=1) {
		printf("not-magic");
	} else if (checkVerticalSum(array,total,size)!=1) {
		printf("not-magic");
	} else if (checkDiagonalSum(array,total,size)!=1) {
		printf("not-magic");
	} else {	
		printf("magic");
	}
	
	
	for (i=0; i<size; i++) {
		free(array[i]);
	}
	free(array);
}

int checkDifferent(int **array, int size) {
	int i;
	for (i=0; i<size; i++) {
		if (exists(array, i, size)==-1) {
			return -1; //does not exist in this matrix, cant be magic
		}
	}
	return 1;
}

int exists(int **array, int query, int size) {
	int i;
	int j;
	for (i=0; i<size; i++) {
		for (j=0; j<size; j++){
			if (array[i][j] == query){
				return 1;
			}
		}
	}
	return -1;
}

int checkHorizontalSum(int **array, int same, int size){
	int i;
	int j;
	int total;
	for (i=0; i<size; i++) {
		total = 0;
		for (j=0; j<size; j++) {
			total = total + array[i][j];
		}
		if (total != same) {
			return -1; //definitely not a magic square 
		}
	}
	return 1;
}

int checkVerticalSum(int **array, int same, int size){
	int i;
	int j;
	for (j=0; j<size; j++) {
		total = 0;
		for (i=0; i<size; i++) {
			total = total + array[i][j];
		}
		if (total != same) {
			return -1; //definitely not a magic square 
		}
	}
	return 1;
}

int checkDiagonalSum(int **array, int same, int size){
	int i;
	int total = 0;
	for (i=0; i<size; i++) {
		total = total + array[i][i];
	}
	if (total != same) {
		return -1;
	}
	
	total = 0;
	for (i=0; i<size; i++) {
		total = total + array[size-1-i][i];
	}
	if (total != same) {
		return -1;
	}
	
	return 1;
}