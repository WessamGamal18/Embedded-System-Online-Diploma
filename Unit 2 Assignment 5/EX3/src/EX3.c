/*
 ============================================================================
 Name        : EX3.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void) {
	char array[100];
	printf("Input a string : ");
	fflush(stdin); fflush(stdout);
	gets(array);
	int i,length = strlen(array);
	char *ptr ;
	ptr = array+length-1;
	for (i=0;i<length;i++)
	{
		printf("%c",*ptr);
		ptr--;
	}

	return 0;
}
