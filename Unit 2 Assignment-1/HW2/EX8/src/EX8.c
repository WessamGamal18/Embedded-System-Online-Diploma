/*
 ============================================================================
 Name        : EX8.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	float x,y,Result;
	char w;
	printf("Enter operatoreither + or - or * or / :");
	fflush(stdin); fflush(stdout);
	scanf("%c",&w);
	switch (w)
	{
	case '+' :
	{
		printf("Enter two operands :");
		fflush(stdin); fflush(stdout);
		scanf("%f %f",&x ,&y);
		Result = x+y;
		printf("%g + %g = %g ",x,y,Result);
	}
	break;
	case '-' :
	{
		printf("Enter two operands :");
		fflush(stdin); fflush(stdout);
		scanf("%f %f",&x ,&y);
		Result = x-y;
		printf("%g - %g = %g ",x,y,Result);
	}
	break;
	case '*' :
	{
		printf("Enter two operands :");
		fflush(stdin); fflush(stdout);
		scanf("%f %f",&x ,&y);
		Result = x*y;
		printf("%g * %g = %g ",x,y,Result);
	}
	break;
	case '/' :
	{
		printf("Enter two operands :");
		fflush(stdin); fflush(stdout);
		scanf("%f %f",&x ,&y);
		Result = x/y;
		printf("%g / %g = %g ",x,y,Result);
	}
	break;
	default :
	{
		printf("Wrong choice");
	}
	}
	return 0;
}
