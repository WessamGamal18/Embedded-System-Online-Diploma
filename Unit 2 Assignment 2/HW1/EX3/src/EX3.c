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

int main(void) {
	int x,y,i,j;
	int matrix[10][10],transpose[10][10];
	printf("Enter rows and column of matrix :");
	fflush(stdin); fflush(stdout);
    scanf("%d%d", &x, &y);
	printf("Enter elements of matrix :\n");
	for (i=0 ; i<x ; i++)
	{
		for (j=0 ; j<y ; j++)
		{
			printf("Enter elements of a%d%d :",i+1,j+1);
			fflush(stdin); fflush(stdout);
			scanf("%d",&matrix[i][j]);
			transpose[j][i] = matrix[i][j];
		}
	}
	printf("Entered Matrix : \n");
	for (i=0 ; i<x ; i++)
	{
		for (j=0 ; j<y ; j++)
		{
			printf("%d  ",matrix[i][j]);
		}
		printf("\n");
	}
	printf("Transpose Matrix : \n");
	for (i=0 ; i<y ; i++)
	{
		for (j=0 ; j<x ; j++)
		{
			printf("%d  ",transpose[i][j]);
		}
		printf("\n");

	}
	return 0;
}
