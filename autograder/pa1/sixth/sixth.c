#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include "sixth.h"

int main(int argc, char **argv) {
	size = strlen(argv[1]);
	
	char *compressed = (char *)malloc(size+1);
	
	int i = 0;
	for (i=0;i<size;i++) {
		compressed[i] = argv[1][i];
	}
	compressed[size] = '\0';
	
	int j = 1;
	int counter = 0; //number of chars after that are the same
	char same;
	
	for (i=0; i<strlen(compressed); i++) {
		counter = 0; //start counter
		printf("CompareMe%c\n", argv[1][i]);
		same = argv[1][i];
		for (j=i+1; j<strlen(compressed); j++) {
			if (argv[1][j] != same) {
				if (counter==0) {
					extend(compressed, j);
					compressed[i+1] = "1";
				} else if (counter==1) {
					compressed[i+1] = "2";
				} else {
					squash(compressed, i+1, compressed-1);
				}
				i++;
				break;
			}
			counter++; //continue counter
			printf("%c\n", argv[1][j]);
		}
		if (j==strlen(compressed)) {
			if (counter==0) {
				extend(compressed, j);
				compressed[i+1] = "1";
			} else if (counter==1) {
				compressed[i+1] = "2";
			} else {
				squash(compressed, i+1, compressed-1);
			}
			break;
		}
		//check if j reached the end
		printf("\n");
	}
	/*
	check which string is longer
	
	*/
	printf("%s\n", compressed);
	free(compressed);
	return 0;
}


void extend(char *str, int index) {
	char *ans = (char *)malloc(strlen(str)+2);
	int i;
	for (i=0; i<index; i++) {
		ans[i] = str[i];
	}
	//ans[index];
	for (i=index; i<strlen(str); i++) {
		ans[i+1] = str[i];
	}
	ans[strlen(str)+1] = '\0';
	
	free (str);
	str = ans;
	return;
}

void squash(char *str, int index, int decreaseBy) { //decreaseBy is the num of characters to cut off, 1 for aaa -> a3
	char *ans = (char *)malloc(strlen(str)+1-decreaseBy);
	int i;
	for (i=0; i<index; i++) {
		ans[i] = str[i];
	}
	//ans[index];
	for (i=index+1; i<strlen(ans)-1; i++) {
		ans[i] = str[i+decreaseBy];
	}
	ans[strlen(ans)-1] = '\0';
	
	free (str);
	str = ans;
	return;
}