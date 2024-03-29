#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include "sixth.h"

int main(int argc, char **argv) {
	size = strlen(argv[1]);
	
	char *compressed = (char *)malloc(size+1);
	char *ans = (char *)malloc(1);
	int i = 0;
	for (i=0;i<size;i++) {
		compressed[i] = argv[1][i];
	}
	compressed[size] = '\0';
	
	printf("%s\n", compressed);
	
	int counter = 0; //number of chars after that are the same
	char same;
	i=0;
	int j = 1;
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
		// should only get here for final condition
		
		counter++;
		printf("Replace\n");
		
		append(ans, same);
		printf("1\n");
		int numSize = 1+(int)(counter/10);
		printf("2\n");
		char temp[numSize];
		printf("temp:%s\n",temp);
		printf("3 counter %d\n", counter);
		snprintf(temp, sizeof(temp), "%d", counter);
		printf("4 temp %s\n", temp);
		appendNum(ans, temp);
		
		
		printf("Effect:%s\n", compressed);
		i=j;
	}
	/*
	check which string is longer
	
	*/
	printf("%s\n", compressed);
	free(compressed);
	return 0;
}


void append(char *ans, char letter) {
	char *temp = realloc(ans, sizeof(ans)+1);
	ans = temp;
	ans[sizeof(ans)-2] = letter;	
	return;
}

void appendNum(char *ans, char *number) {
	char *temp = realloc(ans, sizeof(ans)+sizeof(number));
	ans = temp;
	strcat(ans, number);
	return;
}

