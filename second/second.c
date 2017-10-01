#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char **argv) {
	
	/*
	peusdocode
	int size;
	scanf("%d", &size);
	
	int array[size];
	
	int i;
	for (i=0; i<size; i++) {
		scanf("%d", &array[i])
	}
	
	sort(array, size);
	
	for (i=0; i<size-1; i++) {
		printf("%d\t", array[i]);
	}
	printf("%d", array[i]);
	
	
	*/
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
				j = i;
			}
		}
		int temp = array[i]; 
		array[i] = lowestRightNow;
		array[j] = temp;
	}
}