#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "seventh.h"

int main(int argc, char **argv) {
	//printf("test to make sure spaces are literally the only delimiter that argv uses to determine indicies\n", );
	int i;
	for (i=1; i<argc; i++) {
		printf("%c", argv[i][strlen(argv[i])-1]);
	}
	
// 	int i;
// //has argc-1 size
// 	char **array = malloc(sizeof(char *)*(argc-1));
// //loops through argc-1 times
// 	for (i=1; i<argc; i++) {
// 		char *word = malloc(sizeof(char)*strlen(argv[i]));
// 		array[i] = word;
// 	}
	
	
	return 1;
}