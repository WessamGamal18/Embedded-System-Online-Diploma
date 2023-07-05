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
int power(int k, int j)
{
	static int i =1;
	while (j!=0)
	{
		i *= k;
		j--;
		power(k,j);
		break;
	}
	return i;
}
int main(void) {
	int x,y;
	printf("Enter base number : ");
	fflush(stdin); fflush(stdout);
	scanf("%d",&x);
	printf("Enter power number(postive integer) : ");
	fflush(stdin); fflush(stdout);
	scanf("%d",&y);
	if (y>=0)
		printf("%d^%d = %d",x,y,power(x,y));
	else
		printf("Error!! you entered negative power ");


	return 0;
}
