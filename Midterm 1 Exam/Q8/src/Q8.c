/*
 ============================================================================
 Name        : Q8.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	        int i,a[5]={1,2,3,4,5},b[10];
	        printf("output : ");
	        for (i=0;i<5;i++)
	        {
	        	b[i]= a[4-i];
	        	printf("%d ",b[i]);
	        }

			return 0;
}

