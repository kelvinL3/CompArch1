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
		int *array = (int *) malloc(sizeof(int) * size);
		int *baseArray = (int *) malloc(sizeof(int) * size);
	}
	
	printf("Flag 2\n");
	//reading file into array
	int j;
	for (i=0; i<size; i++) {
		for (j=0; j<size; j++) {
			printf("try scan");
			fscanf(f, " %d", &array[i][j]); //read into array
			printf("scanned: %d\n",array[i][j]);
			if (j<size-1) {
				fscanf(f, "\t");
			}
			baseArray[i][j] = array[i][i]; //copy over into baseArray
		}
		if (i<size-1) {
			fscanf(f, "\n");
		}
	}
	printf("Flag 3\n");
//multiply the matrix size times
	int times;
	fscanf(f, "%d", &times);
	while (times>0) {
		//baseArray increases every time
		multiply(baseArray, array);
		times--;
	}
	printf("Flag 4\n");
//print out the matrix with no extra white space and no extra newline at end
	for (i=0; i<size-1; i++) {
		for (j=0; j<size-1; j++) {
			printf("%d\t", baseArray[i][j]);
		}
		printf("%d\n", baseArray[i][j]);
	}
	printf("%d", baseArray[i][j]);
	printf("Flag 5\n");
//free all our malloced arrays
	for (i=0; i<size; i++) {
		free(array[i]);
		free(baseArray[i]);
	}
	free(array);
	free(baseArray);
	return 0;
}

void multiply(int **baseArray, int **array) {
	int i; int j;
	
	int **array1 = (int **)malloc(sizeof(int *) * size);
	for (i=0; i<size; i++) {
		int *array1 = (int *) malloc(sizeof(int) * size);
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
	baseArray = array1;
}

int dot(int **baseArray, int **array, int rowNumber, int colNumber){
	int i; int j;
	int temp=0;
	for (i=0; i<size; i++) {
		temp = temp + ((baseArray[rowNumber][i])*(array[i][colNumber]));
	}
	return temp;
}