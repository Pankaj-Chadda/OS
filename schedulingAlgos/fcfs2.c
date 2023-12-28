#include<stdio.h>
struct process {
    int pid,at,bt,ct,tat,wt;
};
void swap(int *p,int *q)
{
    int temp=*p;
    *p=*q;
    *q=temp;
}
//Sorting the processes based on arrival time
void sortProcess(struct process ps[],int n)
{
    int i=0,j=0;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-1-i;j++)
        {
            if(ps[j].at>ps[j+1].at)
            {
                swap(&ps[j].at,&ps[j+1].at);
                swap(&ps[j].bt,&ps[j+1].bt);
                swap(&ps[j].pid,&ps[j+1].pid);
            }
            else if(ps[j].at==ps[j+1].at)
            {
                if(ps[j].bt>ps[j+1].bt)//sorting based on burst time.
                {
                swap(&ps[j].at,&ps[j+1].at);
                swap(&ps[j].bt,&ps[j+1].bt);
                swap(&ps[j].pid,&ps[j+1].pid);
                }
            }
        }
    }
}
void CompletionTime(struct process ps[],int n)
{   
    ps[0].ct=ps[0].at+ps[0].bt;
    for(int i=1;i<n;i++)
    {
        if(ps[i].at>ps[i-1].ct)
        {
            ps[i].ct=ps[i].at+ps[i].bt;
        }
        else ps[i].ct=ps[i-1].ct+ps[i].bt;
    }
}
void TAT_WT(struct process ps[],int n)
{
    for(int i=0;i<n;i++)
    {
        ps[i].tat=ps[i].ct-ps[i].at;
        ps[i].wt=ps[i].tat-ps[i].bt;
    }
}
int main()
{
    int n,i,j;
    printf("Enter the number of processes:");
    scanf("%d",&n);
    struct process ps[n];
    printf("Enter the arrival times and burst time respectively:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d%d",&ps[i].at,&ps[i].bt);
        ps[i].ct=0;
        ps[i].tat=0;
        ps[i].wt=0;
        ps[i].pid=i+1;
    }
    sortProcess(ps,n);
    CompletionTime(ps,n);
    TAT_WT(ps,n);
    printf("ID\tAT\tBT\tCT\tTAT\tWT\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d",ps[i].pid,ps[i].at,ps[i].bt,ps[i].ct,ps[i].tat,ps[i].wt);
        printf("\n");
    }
    float avgTAT,avgWT;
    int sumTAT=0,sumWT=0;
    for(i=0;i<n;i++)
    {   
        sumTAT+=ps[i].tat;
    }
    avgTAT=(float)sumTAT/n;
    printf("\nAverage turn around time:%f",avgTAT);
    for(i=0;i<n;i++)
    {   
        sumWT+=ps[i].wt;
    }
    avgWT=(float)sumWT/n;
    printf("\nAverage waiting time:%f",avgWT);
    return 0;
}