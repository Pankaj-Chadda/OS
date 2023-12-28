#include<iostream>
#include<algorithm>
#include<queue>
#include<iomanip>
using namespace std;
struct process{
    int pid,at,bt,ct,wt,tat,startTime;
};
bool comparatorAT(struct process a,struct process b)
{
    int x=a.at;
    int y=b.at;
    return (x<y);
}
bool comparatorPID(struct process a,struct process b)
{
    
    int x=a.pid;
    int y=b.pid;
    return (x<y);
}

int main()
{
    int n,index,i,tq;
    cout<<"Enter the number of processes:";
    scanf("%d",&n);
    int remainingBt[n];
    struct process p[n];
    queue<int> q;
    bool visited[n]={false};
    int currentTime=0;
    int completed=0;
    cout<<fixed<< setprecision(2);
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
    cout<<"\nEnter the time quanta:";
    cin>>tq;
    sort(p,p+n,comparatorAT);
    q.push(0);
    visited[0]=true;
    while(completed !=n)
    {
        index=q.front();
        q.pop();
        if(remainingBt[index]==p[index].bt)
        {
            p[index].startTime=max(currentTime,p[index].at);
            currentTime=p[index].startTime;
        }
        if(remainingBt[index]-tq >0)
        {
            remainingBt[index]-=tq;
            currentTime+=tq;
        }
        else
        {
            currentTime+=remainingBt[index];
            remainingBt[index]=0;
            completed++;
            p[index].ct==currentTime;
            p[index].tat=p[index].ct-p[index].at;
            p[index].wt=p[index].tat-p[index].bt;
            //p[index].tat=p[index].ct-p[index].at;

        }
        for(i=1;i<n;i++)
        {
            if(remainingBt[i]>0 && p[i].at<=currentTime && visited[i]==true)
            {
                q.push(i);
                visited[i]=true;
            }
        }
        if(remainingBt[index]>0)
        {
            q.push(index);
        }
        if(q.empty())
        {
            for(i=1;i<n;i++)
            {
                if(remainingBt[i]>0)
                {
                    q.push(i);
                    visited[i]=true;
                    break;
                }
            }
        }
    }
    sort(p,p+n,comparatorPID);
    printf("ID\tAT\tBT\tCT\n");
    for(i=0;i<n;i++)
    {
       cout<<p[i].pid<<"\t"<<p[i].at<<"\t"<<p[i].bt<<"\t"<<p[i].ct<<endl;
    }
}