/*
 ============================================================================
 Name        : Q6.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	   int i,j,res;
	   int array[7] = {4,2,5,2,5,7,4};
	   j=0;
	   while (i<7)
	   {
		   if ( array[i] == array[j] && i != j)
		   {
			   i++;
			   j=0;
			   continue;
		   }
		   j++;
		   if (j>7 && i<7)
		   {
			   i++;
		   }
		   else
		   {
			   res = array[i];
		   }

	   }
	   printf("output : %d",res);
	   return 0;
	}
