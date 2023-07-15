/*
 ============================================================================
 Name        : EX5.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
struct SData
{
	char name[50];
	int id;
};

int main(void) {
	struct SData emp1={"Alex",1002},emp2={"Ahmed",1003},emp3={"Mohamed",1004};
	struct SData *array[]={&emp1,&emp2,&emp3};
	struct SData *(*ptr)[3]=&array;

	printf("Employee Name : %s",(**(*ptr)).name);
	printf("\nEmployee ID : %d\n",(**(*ptr)).id);

	printf("\nEmployee Name : %s",(**(*ptr+1)).name);
	printf("\nEmployee ID : %d\n",(**(*ptr+1)).id);

	printf("\nEmployee Name : %s",(**(*ptr+2)).name);
	printf("\nEmployee ID : %d",(**(*ptr+2)).id);
	return 0;
}
