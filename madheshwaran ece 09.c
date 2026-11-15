#include<stdio.h>
struct student{
	int rollno;
    char name[50];
    float mark;
};
union contact{
	char phone[15];
	char email[50];
};
int main() {
	struct student s;
	union contact c;
	FILE*fp;
	printf("enter student roll number:");
	scanf("%d",&s.rollno);
	printf("enter student name:");
	scanf("%s",s.name);
	printf("enter student mark:");
	scanf("%f",&s.mark);
	printf("enter phone number:");
	scanf("%s",c.phone);
	fp=fopen("student.txt","w");
	if(fp==NULL){
		printf("unale to open file.");
		return 0;  
	}
	fprintf(fp,"roll number:%d\n",s.rollno);
	fprintf(fp,"name:%s\n",s.name);
	fprintf(fp,"mark:%2f\n",s.mark);
	fprintf(fp,"phone:%s\n",c.phone);
	fclose(fp);
	printf("\nstudent details written to file successfully.\n");
	fp=fopen("student.txt","r");
	if(fp==NULL){
		printf("unable to open file.");
		return 0;
	}
	printf("\n-----STUDENT DETAILS-----\n");
	while(fscanf(fp,"%[^\n]%*c",s.name)==1)
	{
		printf("%s\n",s.name);
	}
	fclose(fp);
	return 0;
}