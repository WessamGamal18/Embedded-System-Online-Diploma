/*
 ============================================================================
 Name        : 2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	char z;
	printf("Enter an alphabet :");
	fflush(stdin); fflush(stdout);
	scanf("%c",&z);
	switch (z)
	{
	case 'a':
	case 'A':
	{
		printf("%c is a Vowel ",z);
	}
	break;
	case 'e':
	case 'E':
	{
		printf("%c is a Vowel ",z);
	}
	break;
	case 'i':
	case 'I':
	{
		printf("%c is a Vowel ",z);
	}
	break;
	case 'o':
	case 'O':
	{
		printf("%c is a Vowel ",z);
	}
	break;
	case 'u':
	case 'U':
	{
		printf("%c is a Vowel ",z);
	}
	break;
	default :
		printf("%c is a Consonant ",z);

	}

}
