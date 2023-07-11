/*
 ============================================================================
 Name        : Q9.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  	char text[100];
  	int i, j, x, start, y;
  	printf("Please enter a string : ");
  	fflush(stdin); fflush(stdout);
  	gets(text);
  	x = strlen(text);
  	y = x - 1;

  	printf("Output : ");
  	for(i = x - 1; i >= 0; i--)
	{
		if(text[i] == ' ' || i == 0)
		{
			if(i == 0)
			{
				start = 0;
			}
			else
			{
				start = i + 1;
			}
			for(j = start; j <= y; j++)
			{
				printf("%c", text[j]);
			}
			y = i - 1;
			printf(" ");
		}
	}

  	return 0;
}
