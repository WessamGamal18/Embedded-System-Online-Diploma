/*
 ============================================================================
 Name        : EX6.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int x=1,sum=0,y;
	printf("Enter an integer : ");
	fflush(stdin); fflush(stdout);
	scanf("%d",&y);
	while (x<=y)
	{
		sum += x;
		x++;
	}
	printf("Sum = %d",sum);
	return 0;
}
