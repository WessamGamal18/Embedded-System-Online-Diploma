/*
 ============================================================================
 Name        : Q1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {
	        int num,z,res =0;
	        printf("enter a number : ");
	        fflush(stdin); fflush(stdout);
	        scanf("%d",&num);
	        while (num != 0)
	        {
	        	z = num%10;
	        	res += z;
	        	num /= 10;
	        }
	        printf("Sum of digits = %d", res);


			return 0;
}

