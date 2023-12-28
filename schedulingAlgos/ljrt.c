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
        int maxIndex=-1;
        int maximum=-1;
        for(i=0;i<n;i++)
        {
            if(p[i].at<=currentTime && isCompleted[i]==false)
            {
                if(remainingBt[i]>maximum)
                {
                    maximum=remainingBt[i];
                    maxIndex=i;
                }
                if(remainingBt[i]==maximum)
                {
                    if(p[i].at < p[maxIndex].at)
                    {
                    maximum=remainingBt[i];
                    maxIndex=i;
                    }
                }
            }
        }
    if(maxIndex==-1)
    {
        currentTime++;
    }
    else {
        // if(remainingBt[maxIndex]==p[maxIndex].bt)//To calculate start time of a process very first time 
        // {
        //     p[maxIndex].startTime=currentTime;
        // }
        remainingBt[maxIndex]-=1;
        currentTime++;
        prev=currentTime;
        if(remainingBt[maxIndex]==0)
        {
            p[maxIndex].ct=currentTime;
            p[maxIndex].tat=p[maxIndex].ct-p[maxIndex].at;
            p[maxIndex].wt=p[maxIndex].tat-p[maxIndex].bt;
            completed++;
            isCompleted[maxIndex]=true;
            currentTime=p[maxIndex].ct;
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