/*
Ques. 19. There are 5 processes and 3 resource types, resource A with 10 instances, B with 5
instances and C with 7 instances. Consider following and write a c code to find whether the
system is in safe state or not?
Available 		Processes 		Allocation 		  Max
A  B  C 		 				A  B  C  		A  B  C
3  3  2 	 		P0  		0  1  0  		7  5  3
	         		P1  		2  0  0  		3  2  2
		     		P2  		3  0  2  		9  0  2
             		P3  		2  1  1  		2  2  2
             		P4  		0  0  2  		4  3  3
*/

#include<stdio.h>
#include<conio.h>
int main()
{
	int no_of_proc;
	int no_of_reso;
	
	printf("\nEnter number of Processes: ");
	scanf("%d",&no_of_proc);
	
	printf("\nEnter number of Resources: ");
	scanf("%d",&no_of_reso);
	
	int allo[no_of_proc][no_of_reso];
	int max[no_of_proc][no_of_reso];
	int avail[no_of_reso];
	
	int i,j;
	
	printf("\n-----Enter values for available array-----\n");
	for(i=0;i<no_of_reso;i++)
	{
		printf("\nEnter (%d): ",i+1);
		scanf("%d",&avail[i]);
	}
	
	printf("\n-----Enter values for Allocation array-----\n");
	for(i=0;i<no_of_proc;i++)
	{
		for(j=0;j<no_of_reso;j++)
		{
			printf("\nEnter (%d,%d): ",i,j);
			scanf("%d",&allo[i][j]);
		}
	}
	
	printf("\n-----Enter values for Max array-----\n");
	for(i=0;i<no_of_proc;i++)
	{
		for(j=0;j<no_of_reso;j++)
		{
			printf("\nEnter (%d,%d): ",i,j);
			scanf("%d",&max[i][j]);
		}
	}
	
	printf("\n\n-----Complete Resource Allocation Graph------\n\n");
	
	printf("\n\nAvailable\n");
	for(i=0;i<no_of_reso;i++)
	{
		printf("%d\t",avail[i]);
	}
	
	printf("\n\nAllocation\n");
	for(i=0;i<no_of_proc;i++)
	{
		for(j=0;j<no_of_reso;j++)
		{
			printf("Process P%d: %d \t",i,allo[i][j]);
		}
		printf("\n");
	}
	
	printf("\n\nMax\n");
	for(i=0;i<no_of_proc;i++)
	{
		for(j=0;j<no_of_reso;j++)
		{
			printf("Process P%d: %d \t",i,max[i][j]);
		}
		printf("\n");
	}
	
	printf("\n-----NOW THE SOLUTION  START-----\n\n");
	
	
	int count1=0;
	int count2=0;
	int proc_state[no_of_proc];
	
	for(i=0;i<no_of_proc;i++)
	{
		proc_state[i]=0;
	}
	
	int x=0;
	for(x=0;x<no_of_proc;x++)
	{
		//printf("loop1");
		for(i=0;i<no_of_proc;i++)
		{
			count1=0;
			count2=0;
		//	printf("Process State: %d",proc_state[i]);
			if(proc_state[i]==0)
			{
				//printf("\n**\t  Process P%d   **",i);
				for(j=0;j<no_of_reso;j++)
					{
						if(max[i][j]-allo[i][j]<=0)
						{
							count1=count1+1;
						}
					
						if((avail[j]+allo[i][j])>=max[i][j])
						{
							count2=count2+1;
						}
					}
				if(count1==no_of_reso||count2==no_of_reso)
				{
					proc_state[i]=1;
					printf("\n**\tProcess P%d COMPLETED  **",i);
					int y=0;
					for(y=0;y<no_of_reso;y++)
					{
						avail[y]=avail[y]+allo[i][y];
					}
					
					printf("\n\n PRESENT AVAILABLE RESOURCES:  ");
					int z=0;
					for(z=0;z<no_of_reso;z++)
					{
						printf("\t%d",avail[z]);
					}
					printf("\n");

				}
			}
		}
	}
	
	int count3=0;
for(i=0;i<no_of_proc;i++)
	{
		if(proc_state[i]==1)
		{
			count3=count3+1;	
		}
	}
if(count3==no_of_proc)
{
	printf("\n\n FINAL AVAILABLE RESOURCES:  ");
	for(i=0;i<no_of_reso;i++)
	{
		printf("\t%d",avail[i]);
	}
	printf("\n\n\t\t*****    SAFE STATE     *****\n");
}
else
{
	printf("\n\t\t****   NOT SAFE STATE   *****\n");
}
	
	
}


