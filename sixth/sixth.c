#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char **argv) {
	char *uncompressed = malloc(strlen(argv[1]));
	uncompressed = argv[1];
	char *compressed = (char *)malloc(strlen(uncompressed)+1);
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
						//the string GROWS in this case, keep the letter and add 1
					} else if (freq == 2) {
						//the string stays at the same size
					} else if (freq >= 3) {
						//the string SHRINKS, replace the second letter with the freq, call another function to excise the rest
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

//cut out [low, high], inclusive
char *cutOutFromString(char *str, int size, int low, int high) {
	//since str is dynamically allocated, cant use strlen()
	int i;
	for (i=low; i<=high; i++) {
		//check if the place im taking from is in bounds
		if () {
			
		}
	}
}