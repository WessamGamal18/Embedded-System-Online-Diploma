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
	int x;
	printf("Enter an integer you want to check : ");
	fflush(stdin); fflush(stdout);
	scanf("%d",&x);
	if (x == 0)
		printf("you entered zero");
	else if (x%2 == 1)
		printf("%d is odd",x);
	else
		printf("%d is even",x);

	return 0;
}
