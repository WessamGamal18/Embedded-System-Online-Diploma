/*
 ============================================================================
 Name        : EX4.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int x,y,z,i,matrix[100];
	printf("Enter number of elements : ");
	fflush(stdin); fflush(stdout);
	scanf("%d",&x);
	for (i=0 ; i<x ; i++)
	{
		matrix[i] = i+1;
	}
	for (i=0 ; i<x ; i++)
	{
		printf("%d  ",matrix[i]);
	}
	printf("\nEnter the element to be inserted : ");
	fflush(stdin); fflush(stdout);
	scanf("%d",&y);
	printf("Enter the location : ");
	fflush(stdin); fflush(stdout);
	scanf("%d",&z);
	for (i=x ; i>=z-1 ; i--)
	{
		if (i != z-1)
		{
			matrix[i]= matrix[i-1];
		}
		if (i == z-1)
		{
			matrix[i] = y;
		}
	}
	for (i=0 ; i<=x ; i++)
	{
		printf("%d   ",matrix[i]);
	}
	return 0;
}
