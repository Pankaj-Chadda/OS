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
    int remainingBt[n];
    printf("Enter the arrival time and burst time respectively:\n");
    for(i=0;i<n;i++)
    {
        
        scanf("%d%d",&p[i].at,&p[i].bt);
        p[i].pid=i+1;
        p[i].ct=0;
        p[i].tat=0;
        p[i].wt=0;
        p[i].startTime=0;
        remainingBt[i]=p[i].bt;
    }
    while(completed!=n)
    {
        int minIndex=-1;
        int minimum=__INT32_MAX__;
        for(i=0;i<n;i++)
        {
            if(p[i].at<=currentTime && isCompleted[i]==false)
            {
                if(remainingBt[i]<minimum)
                {
                    minimum=remainingBt[i];
                    minIndex=i;
                }
                if(remainingBt[i]==minimum)
                {
                    if(p[i].at < p[minIndex].at)
                    {
                    minimum=remainingBt[i];
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
        // if(remainingBt[minIndex]==p[minIndex].bt)//To calculate start time of a process very first time 
        // {
        //     p[minIndex].startTime=currentTime;
        // }
        remainingBt[minIndex]-=1;
        currentTime++;
        prev=currentTime;
        if(remainingBt[minIndex]==0)
        {
            p[minIndex].ct=currentTime;
            p[minIndex].tat=p[minIndex].ct-p[minIndex].at;
            p[minIndex].wt=p[minIndex].tat-p[minIndex].bt;
            completed++;
            isCompleted[minIndex]=true;
            currentTime=p[minIndex].ct;
           // prev=currentTime;
            //isFirstProcess=false;
        }
    }
    }

    printf("ID\tAT\tBT\tCT\tTAT\tWT\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d",p[i].pid,p[i].at,p[i].bt,p[i].ct,p[i].tat,p[i].wt);
        printf("\n");
    }
    float avgTAT,avgWT;
    int sumTAT=0,sumWT=0;
    for(i=0;i<n;i++)
    {   
        sumTAT+=p[i].tat;
    }
    avgTAT=(float)sumTAT/n;
    printf("\nAverage turn around time:%f",avgTAT);
    for(i=0;i<n;i++)
    {   
        sumWT+=p[i].wt;
    }
    avgWT=(float)sumWT/n;
    printf("\nAverage waiting time:%f",avgWT);
return 0;
}