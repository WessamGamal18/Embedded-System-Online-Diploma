/*
 ============================================================================
 Name        : EX5.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int x,y,i,matrix[100];
	printf("Enter number of elements : ");
	fflush(stdin); fflush(stdout);
	scanf("%d",&x);
	for (i=1 ; i<=x ; i++)
	{
		matrix[i-1] = i + (i*10);
	}
	for (i=0 ; i<x ; i++)
	{
		printf("%d  ",matrix[i]);
	}
	printf("\nEnter element to be searched : ");
	fflush(stdin); fflush(stdout);
	scanf("%d",&y);
	for (i=0 ; i<x ; i++)
	{
		if (matrix[i] == y)
		break;
	}
	if (i<x)
		printf("Number found at the location : %d",i+1);
	if (i==x)
		printf("Number not found");

	return 0;
}
