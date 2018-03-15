/*
Ques. 18. Ten students (a,b,c,d,e,f,g,h,i,j) are going to attend an event. There are lots of gift
shops, they all are going to the gift shops and randomly picking the gifts. After picking the gifts
they are randomly arriving in the billing counter. The accountant gives the preference to that
student who has maximum number of gifts. Create a C or Java program to define order of billed
students?
*/

#include<stdio.h>
#include<conio.h>
struct students
{
	char name;
	int gifts;
	int arr_time;
	int burst_time;
	int state;
};

void display(int n,students *student)
{
	
		for(int i=0;i<n;i++)
		{
			printf("Student Name: %c  Arrival Time: %d  Gifts: %d  Burst Time: %d  \n\n",(student+i)->name,(student+i)->arr_time,(student+i)->gifts,(student+i)->burst_time);
		}
		printf("************************************\n");

}

int main()
{
	printf("\n\t\t\t\t\t\t\t\t\tPROBLEM 18\n");

	int i=0,j=0;
	int x=0,y=0;
	int count=1;
	int n;
	int temp;

	printf("Enter number of students : ");
	scanf("%d",&n);
	printf("\n");
	
	struct students student[n];
	struct students temp1;
	struct students temp2;
	
	for(i=0;i<n;i++)
	{
		student[i].name='A'+i;

		printf("Enter arrival time for %c :          ",student[i].name);
		scanf("%d",&student[i].arr_time);
		
		printf("Enter number of gifts bought by %c : ",student[i].name);
		scanf("%d",&student[i].gifts);

		student[i].burst_time=student[i].gifts;
		printf("Burst time for %c is :               %d",student[i].name,student[i].burst_time);
		
		student[i].state=0;
		
		printf("\n\n");
	}

