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
	char text[100],Rev[100];
	int x,y,i;
	printf("Enter the string : ");
	fflush(stdin); fflush(stdout);
	gets(text);
	x = strlen(text);
	y = x;
	for (i=0 ; i<x ; i++)
	{
		Rev[i] = text[y-1];
		y--;
		if (y==0)
			break;
	}
	printf("Reverse string is : %s",Rev);
	return 0;
}
