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
struct SAdd
{
	float real;
	float imag;
};

void Fun(struct SAdd Num[])
{
	printf("Sum = %.1f+%.1fi",(Num[0].real + Num[1].real) , (Num[0].imag + Num[1].imag) );
};

int main(void) {
	struct SAdd Numbers[2];
	int i;
	for (i=0;i<2;i++)
	{
		printf("For %d complex number \n",i+1);
		printf("Enter real and imaginary respectively :");
		fflush(stdin); fflush(stdout);
		scanf("%f %f",&Numbers[i].real,&Numbers[i].imag);
	}
	Fun(Numbers);
	return 0;
}
