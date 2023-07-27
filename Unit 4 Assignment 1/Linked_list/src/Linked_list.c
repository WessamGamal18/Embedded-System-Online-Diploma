/*
 ============================================================================
 Name        : Linked_list.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DPRINTF(...)          {fflush(stdout); \
                              fflush(stdin);  \
							  printf(__VA_ARGS__); \
							  fflush(stdout); \
							  fflush(stdin);}

struct Sdata
{
	int ID;
	char name[40];
	float height;
};
struct SStudent
{
	struct Sdata Student;
	struct SStudent* PNextStudent;

};
struct SStudent* gpFirstStudent=NULL;
void fill_the_record (struct SStudent* new_student)
{
	char temp_text[40];
	DPRINTF("\n Enter the ID : ");
	gets(temp_text);
	new_student->Student.ID = atoi(temp_text);
	DPRINTF(" Enter student full name : ");
	gets(new_student->Student.name);
	DPRINTF(" Enter height : ");
	gets(temp_text);
	new_student->Student.height = atof(temp_text);
}
void AddStudent()
{
	struct SStudent* pLastStudent;
	struct SStudent* pNewStudent;
	if (gpFirstStudent==NULL)
	{
		pNewStudent =(struct SStudent*)malloc(sizeof(struct SStudent));
		gpFirstStudent = pNewStudent;
	}
	else
	{
		pLastStudent = gpFirstStudent;
		while(pLastStudent->PNextStudent)
			pLastStudent = pLastStudent->PNextStudent;
		pNewStudent =(struct SStudent*)malloc(sizeof(struct SStudent));
		pLastStudent->PNextStudent = pNewStudent;
	}
	fill_the_record(pNewStudent);
	pNewStudent->PNextStudent = NULL;
}
int DeleteStudent()
{
	char temp_text[40];
	int selected_id;
	DPRINTF("\n Enter Student ID to be deleted : ");
	gets(temp_text);
	selected_id = atoi(temp_text);
	if(gpFirstStudent)
	{
		struct SStudent* pLastStudent=NULL;
		struct SStudent* pSelectedStudent=gpFirstStudent;
		while (pSelectedStudent)
		{
			if(pSelectedStudent->Student.ID == selected_id)
			{
				if(pLastStudent)
					pLastStudent->PNextStudent = pSelectedStudent->PNextStudent;
				else
					gpFirstStudent = pSelectedStudent->PNextStudent;
			free(pSelectedStudent);
			return 1;
			}
			pLastStudent = pSelectedStudent;
			pSelectedStudent = pSelectedStudent->PNextStudent;
		}

	}
	DPRINTF("\n cannot find student ID.");
	return 0;
}

void ViewStudents()
{
	struct SStudent* pCurrentStudent=gpFirstStudent;
	int count=1;
	if (gpFirstStudent == NULL)
		DPRINTF("\n Empty list");
	while(pCurrentStudent)
	{
		DPRINTF("\n Record Number : %d",count);
		DPRINTF("\n ID : %d",pCurrentStudent->Student.ID);
		DPRINTF("\n name : %s",pCurrentStudent->Student.name);
		DPRINTF("\n height : %g",pCurrentStudent->Student.height);
		pCurrentStudent = pCurrentStudent->PNextStudent;
		count++;
	}
}

void DeleteAll()
{
	struct SStudent* pCurrentStudent=gpFirstStudent;
	if (gpFirstStudent == NULL)
		DPRINTF("\n Empty list");
	while (pCurrentStudent)
	{
		struct SStudent* Ptemp = pCurrentStudent;
		pCurrentStudent = pCurrentStudent->PNextStudent;
		free(Ptemp);
	}
	gpFirstStudent = NULL;
}

int Find_Length()
{
	struct SStudent* pCurrentStudent=gpFirstStudent;
	int count =0;
	if (gpFirstStudent == NULL)
	{
		DPRINTF("\n Empty list");
		return count;
	}
	else
		{
		while (pCurrentStudent)
			{
				pCurrentStudent = pCurrentStudent->PNextStudent;
				count++;
			}
		DPRINTF("\n Length = %d",count);
		return count;
		}

}
int Find_Node()
{
	int count=1,n;
	char temp[40];
	struct SStudent* pCurrentStudent=gpFirstStudent;
	struct SStudent* pLastStudent = pCurrentStudent->PNextStudent;
	DPRINTF("\n Enter n number (from end) : ");
	gets(temp);
	n= atoi(temp);
	while (count<n)
	{
		pLastStudent = pLastStudent->PNextStudent;
		count++;
		if (pLastStudent == NULL)
		{
			DPRINTF("\n list is shoter than this number");
			return 0;
		}
	}
	while (pLastStudent)
	{
		if (pLastStudent->PNextStudent ==NULL)
		{
			DPRINTF("\n ID : %d",pCurrentStudent->Student.ID);
			DPRINTF("\n name : %s",pCurrentStudent->Student.name);
			DPRINTF("\n height : %.2f",pCurrentStudent->Student.height);
			return 0;
		}
		pLastStudent = pLastStudent->PNextStudent;
		pCurrentStudent = pCurrentStudent->PNextStudent;
	}


	return 0;
}

int Loop_Detect()
{
	struct SStudent* pSlow =gpFirstStudent;
	struct SStudent* pFast =pSlow->PNextStudent;
	if (pFast == NULL)
	{
		DPRINTF("\n list has only 1 student");
		return 0;
	}
	pFast = pFast->PNextStudent;
	while (pFast)
	{
		pSlow = pSlow->PNextStudent;
		pFast = pFast->PNextStudent;
		if (pFast == NULL)
		{
			DPRINTF("\n list not looped");
			return 0;
		}
		pFast = pFast->PNextStudent;

		if ( pSlow == pFast)
		{
			DPRINTF("\n this list is looped");
			return 0;
		}
	}
	DPRINTF("\n list not looped");
	return 0;
}


int main(void) {
	char temp_text[40];
	while (1)
{
	DPRINTF("\n===============================");
	DPRINTF("\n\t Choose on of the following options \n");
	DPRINTF("\n 1: Add Student  ");
	DPRINTF("\n 2: Delete Student  ");
	DPRINTF("\n 3: View Students  ");
	DPRINTF("\n 4: Delete All  ");
	DPRINTF("\n 5: Find Length ");
	DPRINTF("\n 6: Find n'th node from end ");
	DPRINTF("\n 7: Loop Detector ");
	DPRINTF("\n Enter Option Number :  ");
	gets(temp_text);
	DPRINTF("\n===============================");
	switch (atoi(temp_text))
	{
	case 1:
		AddStudent();
		break;
	case 2:
			DeleteStudent();
			break;
	case 3:
			ViewStudents();
			break;
	case 4:
			DeleteAll();
			break;
	case 5:
			Find_Length(gpFirstStudent);
			break;
	case 6:
			Find_Node();
			break;
	case 7:
			Loop_Detect();
			break;

	default:
			DPRINTF("\n wrong option ");
			break;
	}
}
	return 0;

}

