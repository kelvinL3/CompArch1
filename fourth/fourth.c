#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char **argv) {
	
	int size;
	//argv is first input, filename?
	fscanf(argv[0], "%d\t", &size);
	int *array[size] = (int **)malloc(sizeof(int *) * size);
	int *baseArray[size] = (int **)malloc(sizeof(int *) * size);
	int i;
	for (i=0; i<size; i++) {
		array[i] = (int *) malloc(sizeof(int) * size);
		baseArray[i] = (int *) malloc(sizeof(int) * size);
	}
	int j;
	for (i=0; i<size; i++) {
		for (j=0; j<size; j++) {
			fscanf(argv[0], "%d\t", &array[i][j]);
			baseArray[i][j] = array[i][i];
		}
	}
	
//multiply the matrix size times
	int times;
	fscanf(argv[0], "%d\t", &times);
	while (times>=0) {
		//baseArray increases every time
		multiply(baseArray, array, size);
		times--;
	}
	
//print out the matrix with no extra white space and no extra newline at end
	for (i=0; i<size-1; i++) {
		for (j=0; j<size-1; j++) {
			printf("%d\t",baseArray[i][j]);
		}
		printf("%d\n",baseArray[i][j]);
	}
	printf("%d",baseArray[i][j]);
	
//free all our malloced arrays
	for (i=0; i<size; i++) {
		free(array[i]);
		free(baseArray[i]);
	}
	free(array);
	free(baseArray);
	return 0;
}

void multiply(int **baseArray, int **array, int size) {
	int i; int j;
	for (i=0; i<size; i++) {
		for (j=0; j<size; j++) {
			baseArray[i][j] = dot(baseArray, array, size, i, j);
		}
	}
}

int dot(int **baseArray, int **array, int size, int rowNumber, int colNumber){
	int i; int j;
	int temp=0;
	for (i=0; i<size; i++) {
		temp = temp + ((baseArray[rowNumber][i])*(array[i][colNumber]));
	}
	return temp;
}