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

int Factorial(int w)
{
	static int result1 = 1;
	while(w != 0)
	{
	    result1 *= w;
	    w--;
	    Factorial(w);
	    break;
	}
	return result1;
}
int main(void) {
	int x;
	printf("Enter a postive number : ");
	fflush(stdin); fflush(stdout);
	scanf("%d",&x);
	if (x<0)
	{
		printf("Please enter a postive number : ");
		fflush(stdin); fflush(stdout);
		scanf("%d",&x);
	}
	else if (x==0)
		printf("Factorial of 0 = : 1");
	else
		printf("Factorial of %d = %d",x,Factorial(x));
	return 0;
}
