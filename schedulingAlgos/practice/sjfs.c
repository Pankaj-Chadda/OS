#include<stdio.h>
#include<stdbool.h>
struct process{
    int pid,at,bt,ct,tat,wt,startTime;
};
int main()
{
    int n,i,completed=0,curTime=0,minimum,minIndex;
    printf("Enter the number of process:");
    scanf("%d",&n);
    struct process p[n];
    printf("\nEnter the arrival time and burst time:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d%d",&p[i].at,&p[i].bt);
        p[i].pid=i+1;
        p[i].ct=p[i].tat=p[i].startTime=p[i].wt=0;
    }
    bool isCompleted[n];
    for(i=0;i<n;i++)
    {
        isCompleted[i]=false;
    }
    while(completed!=n)
    {   minIndex=-1;
        minimum=__INT32_MAX__;
        for(i=0;i<n;i++)
        {
            if(p[i].at<=curTime && isCompleted[i]==false)
            {
                if(p[i].bt<minimum)
                {
                    minimum=p[i].bt;
                    minIndex=i;
                }
                if(p[i].bt==minimum)
                {   
                    if(p[i].at<p[minIndex].at)
                    {
                        minimum=p[i].bt;
                        minIndex=i;
                    }
                }
            }
        }
            if(minIndex==-1)
            {
                curTime++;
            }
            else {
                p[minIndex].startTime=curTime;
                p[minIndex].ct=p[minIndex].startTime+p[minIndex].bt;
                p[minIndex].tat=p[minIndex].ct-p[minIndex].at;
                p[minIndex].wt=p[minIndex].tat-p[minIndex].bt;
                completed++;
                isCompleted[minIndex]=true;
                curTime=p[minIndex].ct;
            }
        
    }
     printf("ID\tAT\tBT\tCT\tTAT\tWT\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",p[i].pid,p[i].at,p[i].bt,p[i].ct,p[i].tat,p[i].wt);
    }
    return 0;
}