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
#include <string.h>

struct Sstudents
{
	char name[100];
	int roll;
	float marks;
};

int main(void) {
	int i;
	struct Sstudents info[100];
	printf("Enter Information for students\n");
	for (i=0;i<100;i++)
	{
		info[i].roll = i+1;
		printf("For roll number %d\n",i+1);
		printf("Enter name : ");
		fflush(stdin); fflush(stdout);
		gets(info[i].name);
		printf("Enter marks : ");
		fflush(stdin); fflush(stdout);
		scanf("%f",&info[i].marks);
	}
	printf("Displaying Information of students\n\n");

	for (i=0;i<100;i++)
	{
		printf("Information for roll number %d \n",info[i].roll);
		printf("Name : %s\n",info[i].name);
		printf("Marks : %.1f\n",info[i].marks);
	}

	return 0;
}
