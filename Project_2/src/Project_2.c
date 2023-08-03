/*
 ============================================================================
 Name        : Project-2.c
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
	char fname[40];
	char lname[40];
	int roll;
	float GPA;
	int cid[10];
};
struct SStudent
{
	struct Sdata Student;
	struct SStudent* PNextStudent;

};
struct SStudent* gpFirstStudent=NULL;
int Check_Roll();
int fill_the_record (struct SStudent* new_student)
{
	char temp_text[40];
	int i,x,j;
	DPRINTF("\n Enter student first name : ");
	gets(new_student->Student.fname);
	DPRINTF(" Enter student last name : ");
	gets(new_student->Student.lname);
	DPRINTF(" Enter the Roll Number : ");
	gets(temp_text);
	new_student->Student.roll = atoi(temp_text);
	while ( Check_Roll(new_student->Student.roll) )
	{
		DPRINTF(" Roll number of student is already token ");
		DPRINTF("\n Enter the Roll Number : ");
		gets(temp_text);
		new_student->Student.roll = atoi(temp_text);
	}
	DPRINTF(" Enter GPA : ");
	gets(temp_text);
	new_student->Student.GPA = atof(temp_text);
	DPRINTF(" Enter number of courses : ");
	gets(temp_text);
	x = atoi(temp_text);
	for (i=0; i<x ; i++)
	{
		DPRINTF(" The Course ID are : ");
		scanf("%d",&new_student->Student.cid[i]);
	}

	for (i=x ; i<10 ; i++ )
		new_student->Student.cid[i] = 0;
	for (i=0;i<x;i++)
	{
		for (j=0;j<x;j++) // check if user repeated course, the program will take this course only 1 time
		{
			if (new_student->Student.cid[i] == new_student->Student.cid[i+j+1])
				new_student->Student.cid[j+i+1] =0;
		}
	}
	DPRINTF("\n Student Details is added successfully ");
	return 0;
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
	pNewStudent->PNextStudent = NULL;
	fill_the_record(pNewStudent);

}
int DeleteStudent()
{
	char temp_text[40];
	int selected_roll;
	DPRINTF("\n Enter Student Roll Number to be deleted : ");
	gets(temp_text);
	selected_roll = atoi(temp_text);

	if(gpFirstStudent)
	{
		struct SStudent* pLastStudent=NULL;
		struct SStudent* pSelectedStudent=gpFirstStudent;
		while (pSelectedStudent)
		{
			if(pSelectedStudent->Student.roll == selected_roll)
			{
				if(pLastStudent)
					pLastStudent->PNextStudent = pSelectedStudent->PNextStudent;
				else
					gpFirstStudent = pSelectedStudent->PNextStudent;
			free(pSelectedStudent);
			DPRINTF("\n The Roll Number is removed successfully ");
			return 1;
			}
			pLastStudent = pSelectedStudent;
			pSelectedStudent = pSelectedStudent->PNextStudent;
		}

	}
	DPRINTF("\n This Roll Number not found");
	return 0;
}

void View_AllStudents()
{
	struct SStudent* pCurrentStudent=gpFirstStudent;
	int i;
	if (gpFirstStudent == NULL)
		DPRINTF("\n Empty list");
	while(pCurrentStudent)
	{
		DPRINTF("\n Student First Name : %s",pCurrentStudent->Student.fname);
		DPRINTF("\n Student Last Name : %s",pCurrentStudent->Student.lname);
		DPRINTF("\n Student Roll Number : %d",pCurrentStudent->Student.roll);
		DPRINTF("\n Student GPA Number : %.2f",pCurrentStudent->Student.GPA);
		for (i=0;i<10;i++)
		{
			if (pCurrentStudent->Student.cid[i] == 0)
				continue;
			DPRINTF("\n The Course ID are : %d",pCurrentStudent->Student.cid[i]);
		}
		pCurrentStudent = pCurrentStudent->PNextStudent;
	}
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
		DPRINTF("\n The total number of students is : %d",count);
		return count;
		}

}

void view_student(struct SStudent* pCurrentStudent)
{
	int i;
	DPRINTF("\n Student First Name : %s",pCurrentStudent->Student.fname);
	DPRINTF("\n Student Last Name : %s",pCurrentStudent->Student.lname);
	DPRINTF("\n Student Roll Number : %d",pCurrentStudent->Student.roll);
	DPRINTF("\n Student GPA Number : %.2f",pCurrentStudent->Student.GPA);
	for (i=0;i<10;i++)
	{
		if (pCurrentStudent->Student.cid[i] == 0)
			continue;
		DPRINTF("\n The Course ID are : %d",pCurrentStudent->Student.cid[i]);
	}

}


int Find_Roll()
{
	char temp_text[40];
	DPRINTF("\n Enter Roll Number :  ");
	gets(temp_text);
	int roll_num = atoi(temp_text);
	struct SStudent* pCurrentStudent=gpFirstStudent;
	if (gpFirstStudent == NULL)
	{
		DPRINTF("\n Empty list");
		return 0;
	}
	while (pCurrentStudent)
		{
		if (pCurrentStudent->Student.roll == roll_num)
		{
			view_student(pCurrentStudent);
			return roll_num;
		}
		pCurrentStudent = pCurrentStudent->PNextStudent;
		}
	DPRINTF("\n Roll Number %d not found",roll_num);
	return 0;

}

int Find_Name()
{
	char temp_text[40];
	int count=0;
	DPRINTF("\n Enter First Name :  ");
	gets(temp_text);
	struct SStudent* pCurrentStudent=gpFirstStudent;
	if (gpFirstStudent == NULL)
	{
		DPRINTF("\n Empty list");
		return 0;
	}
	while (pCurrentStudent)
		{
		if ( stricmp(pCurrentStudent->Student.fname,temp_text) == 0)
		{
			view_student(pCurrentStudent);
			count ++;
		}
		pCurrentStudent = pCurrentStudent->PNextStudent;
		}
	if (count == 0)
		DPRINTF("\n First Name %s not found",temp_text);
	return 0;

}


int UpdateStudent()
{
	int roll_num,choice;
	roll_num = Find_Roll();
	if (roll_num == 0)
	{
		return 0;
	}
	else
	{
		struct SStudent* pCurrentStudent=gpFirstStudent;
		char temp_text[40];
		int i,x,j;
		while (pCurrentStudent)
		{
			if (pCurrentStudent->Student.roll == roll_num)
			{
				DPRINTF("\n Select Data to be updated  ");
				DPRINTF("\n 1: Student First Name  ");
				DPRINTF("\n 2: Student Last Name  ");
				DPRINTF("\n 3: Student Roll Number  ");
				DPRINTF("\n 4: Student GPA  ");
				DPRINTF("\n 5: Student Course ID ");
				DPRINTF("\n Enter Option Number :  ");
				scanf("%d",&choice);
				switch (choice)
				{
				case 1:
					DPRINTF("\n Enter student first name : ");
					gets(pCurrentStudent->Student.fname);
					break;
				case 2:
					DPRINTF("\n Enter student last name : ");
					gets(pCurrentStudent->Student.lname);
					break;
				case 3:
					DPRINTF("\n Enter the Roll Number : ");
					gets(temp_text);
					pCurrentStudent->Student.roll = atoi(temp_text);
					while ( Check_Roll(pCurrentStudent->Student.roll) )
					{
						DPRINTF(" Roll number of student is already token ");
						DPRINTF("\nEnter the Roll Number : ");
						gets(temp_text);
						pCurrentStudent->Student.roll = atoi(temp_text);
					}
					break;
				case 4:
					DPRINTF(" Enter GPA : ");
					gets(temp_text);
					pCurrentStudent->Student.GPA = atof(temp_text);
					break;
				case 5:
					DPRINTF(" Enter number of courses : ");
					gets(temp_text);
					x = atoi(temp_text);
					for (i=0; i<x ; i++)
					{
						DPRINTF(" The Course ID are : ");
						scanf("%d",&pCurrentStudent->Student.cid[i]);
					}
					for (i=x ; i<10 ; i++ )
						pCurrentStudent->Student.cid[i] = 0;
					for (i=0;i<x;i++)
					{
						for (j=0;j<x;j++)
						{
							if (pCurrentStudent->Student.cid[i] == pCurrentStudent->Student.cid[i+j+1])
								pCurrentStudent->Student.cid[j+i+1] =0;
						}
					}
					break;
				default:
					DPRINTF("\n wrong option ");
					break;
				}
				return 1;
			}
			pCurrentStudent = pCurrentStudent->PNextStudent;
		}
		return 0;
	}
}

int Find_Course()
{
	int course,i,count=0;
	DPRINTF("\n Enter the course ID ");
	scanf("%d",&course);
	if (course == 0)
	{
		DPRINTF("\n Course ID %d not exist ",course);
		return 0;
	}
	struct SStudent* pCurrentStudent=gpFirstStudent;
	if (gpFirstStudent == NULL)
	{
		DPRINTF("\n Empty list");
		return 0;
	}
	while (pCurrentStudent)
	{
		for (i=0;i<10;i++)
		{
			if (pCurrentStudent->Student.cid[i] == course )
			{
				view_student(pCurrentStudent);
				count++;
			}
		}
		pCurrentStudent = pCurrentStudent->PNextStudent;
	}
	if (count == 0)
		DPRINTF("\n Course ID %d not found ",course);
	return 1;
}

int Check_Roll(int Roll_Num)
{
	int count = 0;
	struct SStudent* pCurrentStudent=gpFirstStudent;
	while (pCurrentStudent)
	{
		if ((pCurrentStudent->Student.roll) == (Roll_Num))
			count++;
		if (count == 2)
			return 1;
		pCurrentStudent = pCurrentStudent->PNextStudent;
	}
	return 0;
}

int AddFile()
{
	// create new student
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
	pNewStudent->PNextStudent = NULL;

	// fill the students
	FILE* ptr = fopen("Project_1_File.txt", "r");
	char text_temp[40];
	int i,j;
	if (ptr == NULL)
	{
		DPRINTF("\n File can't be opened ");
		return 0;
	}
	for (j=0;j<4;j++)
	{
		fscanf(ptr, "%s", text_temp);
		pNewStudent->Student.roll = atoi(text_temp);
		if (Check_Roll(atoi(text_temp)))
		{
			DPRINTF("\nRoll Number %d is already taken ",atoi(text_temp));
			for (i=0;i<8;i++)
				fscanf(ptr, "%s", text_temp);
			continue;
		}
		fscanf(ptr, "%s", text_temp);
		strcpy(pNewStudent->Student.fname,text_temp);
		fscanf(ptr, "%s", text_temp);
		strcpy(pNewStudent->Student.lname,text_temp);
		fscanf(ptr, "%s", text_temp);
		pNewStudent->Student.GPA = atof(text_temp);
		for (i=0;i<5;i++)
		{
			fscanf(ptr, "%s", text_temp);
			pNewStudent->Student.cid[i] = atoi(text_temp);
		}
		for (i=5;i<10;i++)
			pNewStudent->Student.cid[i] = 0;
		DPRINTF("\nRoll Number %d is saved successfully ",pNewStudent->Student.roll);
		if (j<3)
		{
			pLastStudent = gpFirstStudent;
			while(pLastStudent->PNextStudent)
				pLastStudent = pLastStudent->PNextStudent;
			pNewStudent =(struct SStudent*)malloc(sizeof(struct SStudent));
			pLastStudent->PNextStudent = pNewStudent;
			pNewStudent->PNextStudent = NULL;
		}

	}





    // Closing the file
    fclose(ptr);
    return 1;

}



int main(void) {
	char temp_text[40];
	while (1)
{
	DPRINTF("\n===============================");
	DPRINTF("\n\t Choose on of the following options \n");
	DPRINTF("\n 1: Add the Student Details Manually  ");
	DPRINTF("\n 2: Add the Student Details from Text File  ");
	DPRINTF("\n 3: Find the Student Details by Roll Number  ");
	DPRINTF("\n 4: Find the Student Details by First Name  ");
	DPRINTF("\n 5: Find the Student Details by Course Id ");
	DPRINTF("\n 6: Find the Total number of Students ");
	DPRINTF("\n 7: Delete the Student Details by Roll Number ");
	DPRINTF("\n 8: Update the Student Details by Roll Number ");
	DPRINTF("\n 9: Show all information ");
	DPRINTF("\n 10: To Exit ");
	DPRINTF("\n Enter Option Number :  ");
	gets(temp_text);
	DPRINTF("\n===============================");
	switch (atoi(temp_text))
	{
	case 1: // Done
		AddStudent();
		break;
	case 2: // Done
		AddFile();
		break;
	case 3:
		Find_Roll();
		break;
	case 4:
		Find_Name();
		break;
	case 5:
		Find_Course();
		break;
	case 6: // Done
		Find_Length();
		break;
	case 7: // Done
		DeleteStudent();
		break;
	case 8: // Done
		UpdateStudent();
		break;
	case 9:
		View_AllStudents();
		break;
	case 10:
		return 0;
		break;
	default:
		DPRINTF("\n wrong option ");
		break;
	}
}
	return 0;

}
