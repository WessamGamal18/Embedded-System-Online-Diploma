/*
 ============================================================================
 Name        : EX1.c
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
	char x,text[100];
	int i,y,n=0;
	printf("Enter a string : ");
	fflush(stdin); fflush(stdout);
	gets(text);
	printf("Enter a character to find frequency : ");
	fflush(stdin); fflush(stdout);
	scanf("%c",&x);
	y = strlen(text);
	for (i=0 ; i<=y ; i++)
	{
		if (text[i]==x)
			n += 1;
	}

	printf("frequency of %c : %d",x,n);
	return 0;
}
