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
	int m =29 ;
	printf("Address of m : %p \nValue of m : %d",&m,m);
	int *ab = &m ;
	printf("\nNow ab is assigned with the address of m. ");
	printf("\nAddress of pointer ab : %p\nContent of pointer ab : %d",ab,*ab);
	*ab=34;
	printf("\nThe value of m assigned to %d now. ",m);
	printf("\nAddress of pointer ab : %p\nContent of pointer ab : %d",ab,*ab);
	m=7;
	printf("\nThe value of m assigned to %d now. ",m);
	printf("\nAddress of m ab : %p\nContent of m ab : %d",&m,m);
	return 0;
}
