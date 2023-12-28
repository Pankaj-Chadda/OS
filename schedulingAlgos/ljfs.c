#include<stdio.h>
#include<stdbool.h>
struct process {
    int pid,at,bt,ct,tat,wt,startTime;
};
int main()
{
    int n,i;
    printf("Enter the number of processes:");
    scanf("%d",&n);
    struct process p[n];
    int currentTime=0;
    int completed=0;
    bool isCompleted[20]={false};
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
        int maxIndex=-1;
        int maximum=-1;
        for(i=0;i<n;i++)
        {
            if(p[i].at<=currentTime && isCompleted[i]==false)
            {
                if(p[i].bt>maximum)
                {
                    maximum=p[i].bt;
                    maxIndex=i;
                }
                if(p[i].bt==maximum)
                {
                    if(p[i].at < p[maxIndex].at)
                    {
                    maximum=p[i].bt;
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
        p[maxIndex].startTime=currentTime;
        p[maxIndex].ct=p[maxIndex].startTime+p[maxIndex].bt;
        p[maxIndex].tat=p[maxIndex].ct-p[maxIndex].at;
        p[maxIndex].wt=p[maxIndex].tat-p[maxIndex].bt;
        completed++;
        isCompleted[maxIndex]=true;
        currentTime=p[maxIndex].ct;
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