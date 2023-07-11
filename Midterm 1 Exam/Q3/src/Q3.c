/*
 ============================================================================
 Name        : Q3.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int Prime_Number(int prime[],int num1, int num2)
{
	int i,k=num1,j=0;
	for (i=num1 ; i<=num2; i++)
	{
		if (num1<8 && k!=8)
		{

			for (k=num1 ; k<8 ; k++)
			{
				if (k==2 || k==3 || k==5 || k==7)
				{
					prime[j]= k;
					j++;
				}
			}
		}
		if (i%2!=0 && i%3!=0 && i%5!=0 && i%7!=0 && i!=1)
		{
			prime[j]=i;
			j++;
		}
	}
	return j;
}

int main(void) {
	int x,y,z,w,matrix[100];
	printf("Enter two numbers(intervals) : ");
	fflush(stdin); fflush(stdout);
	scanf("%d%d",&x ,&y);
	w = Prime_Number(matrix,x,y);
	printf("Prime numbers between %d and %d are : ",x,y);
	for (z=0 ; z<w; z++)
	{
		printf("%d ",matrix[z]);
	}
	printf("\n1 is not a prime number");
	return 0;
}
