/*
 ============================================================================
 Name        : Q2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double sqr(double w)
{
	return sqrt(w);
}
int main(void) {
	        int x;
	        printf("enter a number : ");
	        fflush(stdin); fflush(stdout);
	        scanf("%d",&x);
	        printf("output : %.3f",sqr(x));


			return 0;
}
