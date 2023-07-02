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

int main(void) {
	int i,j;
	float a[2][2], b[2][2],Sum[2][2];
	printf("Enter the elements of 1st matrix :\n");
	for (i=0 ; i<2 ; i++)
	{
		for (j=0; j<2 ; j++)
		{
			printf("Enter a%d%d: ",i+1,j+1);
			fflush(stdin); fflush(stdout);
			scanf("%f",&a[i][j]);
		}
	}
	printf("Enter the elements of 2nd matrix :\n");
	for (i=0 ; i<2 ; i++)
	{
		for (j=0; j<2 ; j++)
		{
			printf("Enter b%d%d: ",i+1,j+1);
			fflush(stdin); fflush(stdout);
			scanf("%f",&b[i][j]);
			Sum[i][j] = a[i][j] + b[i][j];
		}
	}
	printf("Sum Of Matrix :\n");
	for (i=0 ; i<2 ; i++)
	{
		for (j=0; j<2 ; j++)
		{
			printf("%.1f  ",Sum[i][j]);

		}
		printf("\n");
	}
	return 0;
}
