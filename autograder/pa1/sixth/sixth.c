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
	
	printf("%s\n", compressed);
	
	int j = 1;
	int counter = 0; //number of chars after that are the same
	char same;
	
	i=0;
	while (i<strlen(compressed)) {
		counter = 0; //start counter
		printf("CompareMe %c\n", compressed[i]);
		same = compressed[i];
		printf("i, j=i+1, strlen(compressed): %d, %d\n", i, (int)strlen(compressed));
		j=j+1;
		while (j<strlen(compressed) && compressed[j] == same) {
			printf("%c", compressed[j]);
			j++;
			counter++; //continue counter
		}
		printf("\n");
		// should only get here for final condition
		
		printf("Replace\n");
		if (counter==0) {
			printf("1\n");
			extend(compressed, j);
			compressed[i+1] = (char)(1);
		} else if (counter==1) {
			printf("2\n");
			compressed[i+1] = (char)(2);
		} else {
			printf("3\n");
			squash(compressed, i+1, counter-1);
		}
		//check if j reached the end
		printf("Effect:%s\n", compressed);
		i++;
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