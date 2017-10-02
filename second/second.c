#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "second.h"


int main(int argc, char **argv) {
	
	FILE *f;
	f = fopen(argv[1], "r");
	
	
	int size;
	fscanf(f, " %d", &size);
	//scanf("%d", &size);
	
	int *array = (int *)malloc(sizeof(int)*size);
	
	int i;
	for (i=0; i<size; i++) {
		fscanf(f, " %d", &array[i]);
		//scanf(" %d", &array[i])
	}
	
	//sort array
	sort(array, size);
	
	//print out the sorted array
	for (i=0; i<size-1; i++) {
		printf("%d\t", array[i]);
	}
	printf("%d", array[i]);
	
	//free array
	free(array);
}

void sort(int *array, int size){
	int i=0;
	for (i=0; i<size; i++) {
		int indexOfLowest;
		int lowestRightNow = array[i];
		int j = i;
		for (j=i; j<size; j++){
			if (array[j]<lowestRightNow) {
				lowestRightNow = array[j];
				indexOfLowest = j;
			}
		}
		int temp = array[i]; 
		array[i] = lowestRightNow;
		array[j] = temp;
	}
	return;
}