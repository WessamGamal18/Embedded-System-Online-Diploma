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

int main(void) {
	char array[27];
	int i;
	for (i=0;i<27;i++)
	{
		array[i]= i + 65;
	}
	char *Parray;
	Parray = array;
	for (i=0;i<26;i++)
	{
		printf("%c\t",*(Parray+i));
	}

	return 0;
}
