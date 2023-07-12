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
#include <string.h>
struct Sstudents
{
	char name[50];
	int roll_num;
	float mark;
};

int main(void) {
	struct Sstudents x;
	printf("Enter information of student : \n\n");
	printf("Enter name : ");
	fflush(stdin); fflush(stdout);
	gets(x.name);
	printf("Enter roll number : ");
	fflush(stdin); fflush(stdout);
	scanf("%d",&x.roll_num);
	printf("Enter marks : ");
	fflush(stdin); fflush(stdout);
	scanf("%f",&x.mark);

	printf("\nDisplaying Information : \n\n");
	printf("Name : %s",x.name);
	printf("\nroll : %d",x.roll_num);
	printf("\nMarks : %.2f",x.mark);


	return 0;
}
