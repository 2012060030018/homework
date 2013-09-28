#include <stdio.h>
#define OK 1;
#define ERROR 0;
#define TRUE 1;
#define FALSE 1;

typedef struct student
{
     int sq;   
	 char name[20];
	 char num[20];
	 char sex[8];
	 int grade ;
}student;


typedef struct Student
{
	student stu;
	struct Student * next;
}Student,*StudentLink;

void addStudent(StudentLink L);
void deleteStudent(StudentLink L,int pos);
void gradeStudent(StudentLink L,int pos,int grade);
void listAllStudent(StudentLink L);
void listStudent(StudentLink L,int pos);
void printStudent(student stu);
void print();