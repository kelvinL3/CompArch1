#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "sixth.h"

int main(int argc, char **argv) {
	size = strlen(argv[1]);
	char *uncompressed = malloc(size);
	char *compressed = (char *)malloc(size);
	int i;
	for (i=0;i<size;i++) {
		uncompressed[i] = argv[1][i];
		compressed[i] = argv[1][i];
	}
	if (compressed==NULL) {
		printf("mallocFail!\n");
		exit(0);
	}
	
	//check for only letters, capital and lowercase
	int check = validString(uncompressed);
	if (check == 1) { //detect a non letter
		printf("error");
		exit(0);
	}
	
	
	int j;
	int freq;
	char toCompress;
	for (i=0; i<strlen(compressed); i++) { //looping on the char to be compressed
		toCompress = compressed[i];
		for (j=i+1; j<size; j++) { //find where the char changes
			if (compressed[j]!=toCompress) {
				//reached end of same character sequence
				//replace compressed[i,j-1]
				
					//replace from [i, j)
					//find and put number at i+1
					freq = j-i;
					if (freq == 1) {
						//the string GROWS in this case, keep the letter and add 1
						compressed = growString(compressed, i);
					} else if (freq == 2) {
						//the string stays at the same size
						compressed[i+1] = '2';
					} else if (freq >= 3) {
						//the string SHRINKS, replace the second letter with the freq, call another function to excise the rest
						compressed = cutOutFromString(compressed, i, j-1);
					}
					i++;
					
					//compressed[i+1] = (char) freq;
					
					//keep on copying data from (j->i+2) until j hits the upper bound
					//add the null terminator after where i+2 stopped
			}
		}
		freq = j-i;
		if (freq == 1) {
			compressed = growString(compressed, i);
		} else if (freq == 2) { //there are two same characters at the end
			compressed[i+1] = '2';
		} else if (freq >= 3) {
			compressed = cutOutFromString(compressed, i, j-1);
		}
		i++;
		//compressed[i+1] = (char) freq;
	}
	
	if (strlen(compressed)>=strlen(uncompressed)) {
		printf("%s\n", compressed);
	} else {
		printf("%s\n", uncompressed);
	}
	
	//dont forget to check for the listed errors 
	
	free(uncompressed);
	free(compressed);
	return 0;
}

int validString(char *str){
	int i;
	char x;
	for (i=0;i<size;i++) {
		x = str[i];
		if (!((x>='A'&&x<='Z')||(x>='a'&&x<='z'))) { //if the character is not a letter
			return 1;
		}	
	}
	return 0;
}

char *growString(char *str, int index) { //index is the index of the singleton char
	char *temp = (char *)malloc(size+1);
	int i;
	for (i=0; i<=index; i++) {
		temp[i] = str[i];
	}
	temp[index+1] = (char)1;
	for (i=index+1; i<size; i++) {
		temp[i+1] = str[i];
	}
	free(str);
	return temp;
}

//cut out [low, high], inclusive, replace with char and number
char *cutOutFromString(char *str, int low, int high) {
	//since str is dynamically allocated, cant use strlen()
	char *temp = (char *)malloc(size-(high-low)+1);
	int i;
	for (i=0; i<low; i++) {
		temp[i] = str[i];
	}
	for (i=high+1; i<size; i++) {
		temp[i-(high-low)+1] = str[i];
	}
	temp[low+1] = (char)(high-low+1);
	// a, low, b, c, d, high, e, f; size=8
	// 0, 1  , 2, 3, 4, 5   , 6, 7; 
	// a, low, n, e, f				size=5
	free(str);
	return temp;
}