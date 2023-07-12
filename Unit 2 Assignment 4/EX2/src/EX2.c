/*
 ============================================================================
 Name        : EX2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
struct SNumbers
{
	int feet;
	float inch;
};
int main(void) {
	int i,result;
    float rem=0;
	struct SNumbers dist[2];
	for (i=0;i<2;i++)
	{
		printf("Enter information for %d distance\n",i+1);
		printf("Enter feet : ");
		fflush(stdin); fflush(stdout);
		scanf("%d",&dist[i].feet);
		printf("Enter inch : ");
		fflush(stdin); fflush(stdout);
		scanf("%f",&dist[i].inch);
		rem += dist[i].inch;
	}
	if (rem>12.0)
	{
		rem-=12.0;
	}

	result = (dist[0].feet) + (dist[1].feet) + (dist[0].inch + dist[1].inch)/12;
	printf("Sum of distance : %d\'-%.1f\"", result,rem);
	return 0;
}
