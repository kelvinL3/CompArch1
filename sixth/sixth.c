#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char **argv) {
	char *uncompressed = malloc(strlen(argv[1]));
	uncompressed = argv[1];
	char *compressed = (char *)malloc(strlen()+1);
	if (compressed==NULL) {
		printf("mallocFail!\n");
		return NULL;
	}
	strcpy(compressed, uncompressed);
	
	int i;
	int j;
	char toCompress;
	for (i=0; i<strlen(compressed); i++) {
		toCompress = compressed[i];
		for (j=i+1; j<strlen(compressed); j++) {
			if (compressed[j]!=toCompress) {
				//reached end of same character sequence
				//replace compressed[i,j-1]
				
					//replace from [i, j)
					//find and put number at i+1
					int freq = j-i;
					if (freq == 1) {
						
					}
					
					compressed[i+1] = (char) freq;
					
					//keep on copying data from (j->i+2) until j hits the upper bound
					//add the null terminator after where i+2 stopped
			}
		}
	}
	
	
	
	
	
	dont forget to check for the listed errors 
	
	free(compressed);
	return 1;
}
