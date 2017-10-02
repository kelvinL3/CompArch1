#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "fifth.h"

int main(int argc, char **argv) {
	
	//file check
	if(access(argv[1], F_OK )==-1) {
		printf("error");
		exit(0);
	}
	
	FILE *f;
	f = fopen(argv[1], "r");
	fscanf(f, "%d\n", &size); //copy size over
	
	int **array = (int **)malloc(sizeof(int *) * size);
	int i;
	for (i=0; i<size; i++) {
		array[i] = (int *) malloc(sizeof(int) * size);
		
	}
	
	//reading file into array
	int j;
	for (i=0; i<size; i++) {
		for (j=0; j<size; j++) {
			fscanf(f, " %d", &array[i][j]); //read into array
		}
	}
	
	printf("\n");
	printMatrix(array);
	printf("\n");
	
	
//sum up the top row, use that as comparison
	int total = 0;
	for (i=0; i<size; i++) {
		total = total + array[i][0];
	}
	if (checkDifferent(array)!=1) {
		printf("1not-magic");
	} else if (checkHorizontalSum(array, total)!=1) {
		printf("2not-magic");
	} else if (checkVerticalSum(array, total)!=1) {
		printf("3not-magic");
	} else if (checkDiagonalSum(array, total)!=1) {
		printf("4not-magic");
	} else {	
		printf("5magic");
	}
	
	
	for (i=0; i<size; i++) {
		free(array[i]);
	}
	free(array);
	return 0;
}

int checkDifferent(int **array) {
	int query;
	for (query=1; query<=(size*size); query++) {
		printf("%d\n", query);
		if (exists(array, query)==-1) {
			return -1; //does not exist in this matrix, cant be magic
		}
	}
	return 1;
}

//helper method for checkDifferent
int exists(int **array, int query) {
	int i;
	int j;
	for (i=0; i<size; i++) {
		for (j=0; j<size; j++){
			printf("%d, ", array[i][j]);
			if (array[i][j] == query){
				return 1;
				printf("\n");
			}
			printf("\n");
		}
	}
	return -1;
}

int checkHorizontalSum(int **array, int same){
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

int checkVerticalSum(int **array, int same){
	int i;
	int j;
	int total;
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

int checkDiagonalSum(int **array, int same){
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

void printMatrix(int **baseArray) {
	int i;
	int j;
	for (i=0; i<size-1; i++) {
		for (j=0; j<size-1; j++) {
			printf("%d\t", baseArray[i][j]);
		}
		printf("%d\n", baseArray[i][j]);
	}
	for (j=0; j<size-1; j++) {
		printf("%d\t", baseArray[i][j]);
	}
	printf("%d", baseArray[i][j]);
}

