/*
 ============================================================================
 Name        : Q5.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
            int i,n,res=0,k;
	        printf("Enter a number : ");
	        fflush(stdin); fflush(stdout);
	        scanf("%d",&i);
	        for (n=0;n<16;n++)
	        {
	        	if (n==0)
	        	{
	        		k=i;
	        		k |= 1;
	        		if (k==i)
	        			res +=1;
	        		k=i;
	        	}
	        	else
				{
	        		k |= 1<<n;
	        		if (k==i)
	        			res +=1;
	        		k=i;
				}

	        }
	        printf("output : %d",res);


			return 0;
}
