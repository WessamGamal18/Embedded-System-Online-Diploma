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
	int x,i;
	float y[100],Avg=0;
	printf("Enter the number of data : ");
	fflush(stdin); fflush(stdout);
	scanf("%d",&x);
	while (x>100)
	{
		printf("Error!!! max number is 100, try again\n");
		printf("Enter the number of data : ");
		fflush(stdin); fflush(stdout);
		scanf("%d", &x);
	}
	for (i=0 ; i<x ; i++)
	{
		printf("%d.Enter number : ",i+1);
		fflush(stdin); fflush(stdout);
		scanf("%f",&y[i]);
		Avg += y[i];
	}
	Avg /= x;
	printf("Average = %g",Avg);
	return 0;
}
