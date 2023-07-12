/*
 ============================================================================
 Name        : EX5.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define Pi 3.141
#define Area(R) (Pi*R*R)
int main(void) {
	int r;
	float area;
	printf("Enter the radius : ");
	fflush(stdin); fflush(stdout);
	scanf("%d",&r);
	area = Area(r);
	printf("Area = %.2f",area);
	return 0;
}
