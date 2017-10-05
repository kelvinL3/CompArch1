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
	
	char *ptr1 = argv[1];
	char *ptr2 = ptr1+1;
	
	
	for (ptr1=argv[1]; ptr1!='\0'; ptr1++) {
		printf("%c\n", *ptr1);
		for (ptr2=ptr1+1; ptr2!='\0'; ptr2++) {
			printf("%c\n", *ptr2);
		}
		printf("\n");
	}
	
	return 0;
}