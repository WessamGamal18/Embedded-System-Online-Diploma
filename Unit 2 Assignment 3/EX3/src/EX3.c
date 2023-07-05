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
static int i =0;
void reverse(char text1[])
{
	int x = strlen(text1);
	static char text2[100];
	if (i<x)
	{
	text2[i] = text1[(x-1)-i];
	i++;
	reverse(text1);
	}
	else
	{
		text2[i+1] = '0';
		puts(text2);
	}

}
int main(void) {
	char text[100];
	printf("Enter a sentence: ");
	fflush(stdin); fflush(stdout);
	gets(text);
	reverse(text);
	return 0;
}
