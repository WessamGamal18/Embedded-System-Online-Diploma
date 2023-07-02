/*
 ============================================================================
 Name        : EX2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>

int main(void) {
	char text[100];
	int i,length=0;
	printf("Enter a string : ");
	fflush(stdin); fflush(stdout);
	gets(text);
	for (i=0 ; i<100 ; i++)
	{
		if (text[i] !=0)
			length += 1;
		if (text[i] ==0)
			break;
	}
	printf("Length of string : %d",length);
	return 0;
}
