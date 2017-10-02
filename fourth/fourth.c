#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "fourth.h"


int main(int argc, char **argv) {
	
	if(access(argv[1], F_OK )==-1) {
		printf("error");
		exit(0);
	}
	
	FILE *f;
	f = fopen(argv[1], "r");
	fscanf(f, "%d\n", &size);
	
	printf("size is: %d\n",size);
	//argv is first input, filename?
	int **array = (int **)malloc(sizeof(int *) * size);
	int **baseArray = (int **)malloc(sizeof(int *) * size);
	int i;
	for (i=0; i<size; i++) {
		int *temp1 = (int *) malloc(sizeof(int) * size);
		int *temp2 = (int *) malloc(sizeof(int) * size);
		array[i] = temp1;
		baseArray[i] = temp2;
	}
	
	//reading file into array
	int j;
	for (i=0; i<size; i++) {
		for (j=0; j<size; j++) {
			fscanf(f, " %d", &array[i][j]); //read into array
			//printf("scanned: %d\n",array[i][j]);
			baseArray[i][j] = array[i][j]; //copy over into baseArray
		}
	}
	
	
	/*printMatrix(baseArray);
	printf("first above\n");
	printMatrix(array);
	printf("second above\n\n\n");*/
	
//multiply the matrix size times
	int times;
	fscanf(f, " %d", &times);
	//printf("times: %d \n", times);
	while (times>1) {
		//printf("again\n");
		//baseArray increases every time
		baseArray = multiply(baseArray, array);
		times--;
	}
	
//print out the matrix with no extra white space and no extra newline at end

	printMatrix(baseArray);
	
	
//free all our malloced arrays
	for (i=0; i<size; i++) {
		//printf("free i=%d\n",i);
		free(array[i]);
		free(baseArray[i]);
	}
	free(array);
	free(baseArray);
	return 0;
}

int ** multiply(int **baseArray, int **array) {
	int i; int j;
	
	int **array1 = (int **)malloc(sizeof(int *) * size);
	for (i=0; i<size; i++) {
		int *temp = (int *) malloc(sizeof(int) * size);
		array1[i] = temp;
	}
	
	
	for (i=0; i<size; i++) {
		for (j=0; j<size; j++) {
			array1[i][j] = dot(baseArray, array, i, j);
		}
	}
	
	for (i=0; i<size; i++) {
		free(baseArray[i]);
	}
	free(baseArray);
	return array1;
}

int dot(int **baseArray, int **array, int rowNumber, int colNumber){
	int i; int j;
	int temp=0;
	for (i=0; i<size; i++) {
		temp = temp + ((baseArray[rowNumber][i])*(array[i][colNumber]));
	}
	return temp;
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

