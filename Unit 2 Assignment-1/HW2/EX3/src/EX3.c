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
	float x,y,z;
	printf("Enter Three Numbers : ");
	fflush(stdin); fflush(stdout);
	scanf("%f %f %f",&x ,&y ,&z);
	if (x>y)
	{
		if (x>z)
			printf("Largest Number : %g",x);
		else
			printf("Largest Number : %g",z);

	}
	else
	{
		if (y>z)
			printf("Largest Number : %g",y);
		else
			printf("Largest Number : %g",z);
	}
	return 0;
}
