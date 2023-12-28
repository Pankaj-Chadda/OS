#include<stdio.h>
#include<stdbool.h>
struct process {
    int pid,at,bt,ct,tat,wt,startTime;
};
int findMax(int a,int b)
{
    return a>b?a:b;
}
int findMin(int a,int b)
{
    return a<b?a:b;
}

int main()
{
    int n,i;
    printf("Enter the number of processes:");
    scanf("%d",&n);
    struct process p[n];
    int currentTime=0,prev=0;
    int completed=0;
   bool isCompleted[20]={false},isFirstProcess=true;
    printf("Enter the arrival time and burst time respectively:\n");
    for(i=0;i<n;i++)
    {
        
        scanf("%d%d",&p[i].at,&p[i].bt);
        p[i].pid=i+1;
        p[i].ct=0;
        p[i].tat=0;
        p[i].wt=0;
        p[i].startTime=0;
    }
    while(completed!=n)
    {
        int minIndex=-1;
        int minimum=__INT32_MAX__;
        for(i=0;i<n;i++)
        {
            if(p[i].at<=currentTime && isCompleted[i]==false)
            {
                if(p[i].bt<minimum)
                {
                    minimum=p[i].bt;
                    minIndex=i;
                }
                if(p[i].bt==minimum)//Helps when two processes have same burst time but different arrival times
                {
                    if(p[i].at < p[minIndex].at)
                    {
                    minimum=p[i].bt;
                    minIndex=i;
                    }
                }
            }
        }
    if(minIndex==-1)
    {
        currentTime++;
    }
    else {
        p[minIndex].startTime=currentTime;
        p[minIndex].ct=p[minIndex].startTime+p[minIndex].bt;
        p[minIndex].tat=p[minIndex].ct-p[minIndex].at;
        p[minIndex].wt=p[minIndex].tat-p[minIndex].bt;
        completed++;
        isCompleted[minIndex]=true;
        currentTime=p[minIndex].ct;
        prev=currentTime;
        isFirstProcess=false;
    }
    }

    printf("ID\tAT\tBT\tCT\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t%d\t%d\t%d",p[i].pid,p[i].at,p[i].bt,p[i].ct);
        printf("\n");
    }
return 0;
}