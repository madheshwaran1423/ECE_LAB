#include<stdio.h>
#define MAX 50
#define SUBJECTS 5
struct Student
{
	int regno;
	char name[50];
	int marks[SUBJECTS];
	int total;
	float average;
	char grade;
};
struct Student students[MAX];
int count = 0;
void calculatorResult(int i)
{
	int j;
	students[i].total = 0;
	for(j = 0;j<SUBJECTS;j++)
	{
		students[i].total += students[i].marks[j];
	}
	students[i].average = students[i].total/5.0;
	if(students[i].average>=90)
		students[i].grade = 'A';
	else if (students[i].average >=80)
		students[i].grade = 'B';
	else if (students[i].average >=70)
		students[i].grade = 'C';
	else if (students[i].average >=60)
		students[i].grade = 'D';
	else if (students[i].average >=50)
		students[i].grade = 'E';
	else
		students[i].grade = 'F';
}
	void addStudent()
	{
		int i;
		printf("\nEnter Register Number: ");
		scanf("%d", &students[count].regno);
		printf("Enter Student Name: ");
		scanf(" %[^\n]", students[count].name);
		printf("Enter marks for 5 subjects:\n");
		for (i = 0;i<SUBJECTS;i++)
		{
			printf("Subject %d: ",i+1);
			scanf("%d", &students[count].marks[i]);
		}
		calculatorResult(count);
		count++;
		printf("\nStudent record added successfully.\n");
	}
	void displayStudents()
	{
		int i;
		printf("\n------------------------------------------------------\n");
		printf("Reg.No\tName\t\tTotal\tAverage\tGrade\n");
		printf("--------------------------------------------------------\n");
		for(i = 0;i <count;i++)
		{
			printf("%d\t%-15s\t%d\t%.2f\t%c\n",
				students[i].regno,
				students[i].name,
				students[i].total,
				students[i].average,
				students[i].grade);
		}
	}
	void searchStudent()
	{
		int regno, i, found = 0;
		printf("\nEnter Register Number: ");
		scanf("%d", &regno);
		for(i = 0;i<count;i++)
		{
			if (students[i].regno == regno)
			{
				printf("\nStudent Found\n");
				printf("Register Number : %d\n",students[i].regno);
				printf("Name		:%s\n",students[i].name);
				printf("Total		:%d\n",students[i].total);
				printf("Average		:%.2f\n",students[i].average);
				printf("Grade		:%c\n",students[i].grade);
				found = 1;
				break;
			}
		}
	    if(!found)
		    printf("\nStudent noy found.\n");
	}
	void displayTopper()
	{
	    int i, topper = 0; 
		if(count==0)
		{
			printf("\nNo records available.\n");
			return;
		}
		for(i = 1;i<count;i++)
		{
			if(students[i].total>students[topper].total)
				topper = i;
		}
		printf("\n==========TOPPER==========\n");
		printf("Register Number : %d\n",students[topper].regno);
		printf("Name		:%s\n", students[topper].name);
		printf("Total		:%d\n",students[topper].total);
		printf("Average		:%.2f\n",students[topper].average);
		printf("Grade		:%c\n",students[topper].grade);
	}
	int main()		
	{
		int choice;
		do
		{
			printf("\n=====STUDENT RESULT MANAGEMENT=====\n");
			printf("1. Add Student\n");
			printf("2. Display Students\n");
			printf("3. Search Student\n");
			printf("4. Display Topper\n");
			printf("5. Exit\n");	
			printf("\nEnter your choice:");
			scanf("%d", &choice);
			switch (choice)
			{
				case 1:
					addStudent();
					break;
				case 2:
					displayStudents();
					break;
				case 3:
				    searchStudent();
					break;
				case 4:
					displayTopper();
					break;
				case 5:
					printf("\nThank you.\n");
					break;
				default:
					printf("\nInvalid choice.\n");
			}
		} while (choice !=5);
	    return 0;
    }
			