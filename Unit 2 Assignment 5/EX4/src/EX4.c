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

int main(void) {
	int array[15],num,i;
	int *Parray;
	printf("Input the number of elements to store in the array (max 15) : ");
	fflush(stdin); fflush(stdout);
	scanf("%d",&num);
	while(num>15)
	{
		printf("Error!! max elements is 15\nInput the number of elements to store in the array (max 15) : ");
		scanf("%d",&num);
	}
	printf("Input 5 number of elements in the array : \n");
	for (i=1;i<=5;i++)
	{
		printf("element - %d : ",i);
		fflush(stdin); fflush(stdout);
		scanf("%d",&array[i-1]);
	}
	printf("The elements of array in reverse order are : \n");
	Parray = array+4;
	for (i=5;i>0;i--)
		{
			printf("element - %d : %d\n",i,*Parray);
			Parray--;
		}
	return 0;
}
