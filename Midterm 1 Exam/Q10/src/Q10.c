/*
 ============================================================================
 Name        : Q10.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
            int i,n,res1=0,res2=0,k,count=0;
	        printf("Enter a number : ");
	        fflush(stdin); fflush(stdout);
	        scanf("%d",&i);
	        for (n=0;n<16;n++)
	        {
	        	if (n==0)
	        	{
	        		k=i;
	        		k |= 1;
	        		if (k!=i)
	        			count +=1;
	        		k=i;
	        	}
	        	if (n!=0 && count ==1)
				{
	        		k |= 1<<n;
	        		if (k==i)
	        			res1 +=1;
	        		else
	        		{
	        			res2 = res1>res2 ? res1:res2;
	        			res1 =0;
	        			count =1;
	        		}
	        		k=i;
				}
	        	if (n!=0 && count!=1)
	        	{
	        		k=i;
	        		k |= 1<<n;
	        		if (k!=i)
	        			count +=1;
	        		k=i;
	        	}

	        }
	        printf("output : %d",res2);


			return 0;
}
