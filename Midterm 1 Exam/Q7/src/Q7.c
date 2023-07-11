/*
 ============================================================================
 Name        : Q7.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	    int i,res;
		printf("enter an number : ");
		fflush(stdin); fflush(stdout);
		scanf("%d",&i);
		res = i*(i+1)/2;
		printf("result : %d",res);

	return 0;
}
