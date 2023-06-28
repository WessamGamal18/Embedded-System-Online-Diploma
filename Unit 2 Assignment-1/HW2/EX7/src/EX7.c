/*
 ============================================================================
 Name        : EX7.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int x=1,fact=1,y;
	printf("Enter an integer : ");
	fflush(stdin); fflush(stdout);
	scanf("%d",&y);
	if (y>0)
	{
		while (x<=y)
			{
				fact *= x;
				x++;
			}
		printf("factorial = %d",fact);
	}
	else
		printf("Error!!! Factorial of negative number doesn't exist");


	return 0;
}
