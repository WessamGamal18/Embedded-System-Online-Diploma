/*
 ============================================================================
 Name        : Q4.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
void Rev()
{
	char c;
	scanf("%c",&c);
	if (c != '\n')
	{
		Rev();
		printf("%c ",c);
	}
}
int main(void) {

	        printf("Enter a sentence : ");
	        fflush(stdin); fflush(stdout);
	        Rev();

			return 0;
}
