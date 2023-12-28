//Banker's Algorithm
#include<stdio.h>
#include<stdbool.h>

struct process{
	int max[10];
	int allocated[10];
	int need[10];
};
void input(struct process ps[],int nop,int avail[],int nor)
{
	for(int i=0;i<nop;i++)
	{
		printf("Enter the process[%d] info\n",i);
		printf("Maximum Need:");
		printf("Enter the number of allocated resources for this process:");
		for(int j=0;j<nor;j++)
		{
			scanf("%d",&ps[i].allocated[j]);
			ps[i].need[j]=ps[i].max[j]-ps[i].allocated[j];
		}
	}
	printf("Enter the available resources:");
	for(int i=0;i<nor;i++)
	{
		scanf("%d",&avail[i]);
	}
}
void showTheInfo(struct process ps[],int nop,int nor)
{
	printf("PID\tMaximum\t\tAllocated\tNeed\n");
	for(int i=0;i<nop;i++)
	{
		printf("P[%d]\t",i);
		for(int j=0;j<nor;j++)
		{
			printf("%d ",ps[i].max[j]);
		}
		printf("\t\t");
		for(int j=0;j<nor;j++)
		{
			printf("%d ",ps[i].allocated[j]);
		}
		printf("\t\t");
		for(int j=0;j<nor;j++)
		{
			printf("%d ",ps[i].need[j]);
		}
		printf("\n");
	}
}
bool applySafetyAlgo(struct process ps[],int available[],int safeSequence[],int nor,int nop)
{
	bool finish[nop];
	int work[nor];
	for(int i=0;i<nor;i++)
	{
		work[i]=available[i];
	}
	for(int i=0;i<nop;i++)
	{
		finish[i]=false;
	}
	bool proceed=true;
	int k=0;
	while(proceed)
	{
		proceed=false;
		for(int i=0;i<nop;i++)
		{
			bool flag=true;
			if(finish[i]==false)
			{
				for(int j=0;j<nor;j++)
				{
					if(proceed[i].need[j]<=work[j])
						continue;
					else {
						flag=false;
						break;
					}	
				}
				if(flag==false)
				{
					continue;
				}
				for(int j=0;j<nor;j++)
				{
					work[j]+=ps[i].allocated[j];
				}
				finish[i]=true;
				safeSequence[k++]=i;
				proceed=true;
			}
		}
	}
	int i;
	for(i=0;i<nop && finish[i]==true;i++)
	{
		continue;
	}
	if(i==nop)
	{
		return true;
	}
	else false;
}
bool isSafeState(struct process ps[],int avail[],int safeSequence[],int nor,int nop)
{
	if(applySafetyAlgo(ps,avail,safeSequence,nor,nop)==true)
		return true;
	return false;
}
int main()
{
	int nop,nor;
	printf("Enter the number of processe:");
	scanf("%d",&nop);
	printf("\nEnter the number of resources:");
	scanf("%d",&nor);
	int available[nor];
	int safeSequence[nop];
	struct process ps[nop];
	printf("\nEnter the details of processes:\n");
	input(ps,nop,available,nor);
	showTheInfo(ps,nop,nor);
	if(isSafeState(ps,available,safeSequence,nor,nop))
	{
		printf("System is in Safe state.");
		printf("Safe Sequence is:");
		for(int i=0;i<nop;i++)
		{
			printf("P[%d] ",safeSequence[i]);
		}
	}
	else {
		printf("System is Unsafe State");
	}
	return 0;
}