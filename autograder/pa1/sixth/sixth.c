#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include "sixth.h"

int main(int argc, char **argv) {
	size = strlen(argv[1]);
	//char *uncompressed = (char *)malloc(size);
	//char *compressed = (char *)malloc(size);
	
	int i = 0;
	int j = 1;
	
	
	for (i=0; i<size; i++) {
		printf("%d\n", argv[i]);
		for (j=0; j<size; j++) {
			printf("%d\n", argv[j]);
		}
		printf("\n");
	}
	
	return 0;
}