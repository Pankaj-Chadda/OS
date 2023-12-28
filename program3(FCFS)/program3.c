#include<stdio.h>
#include<stdlib.h>
struct process{
    int arrival;
    int burst;
    int completion;
    struct process*next;
};
int main()
{
    struct process *start,*temp,*newnode,*prev;
    start=NULL;
    int at,bt,n;
    printf("Enter the number of process:");
    scanf("%d",&n);
    printf("\n");
    for(int i=0;i<n;i++)
    {
        newnode=(struct process*)malloc(sizeof(struct process));
        printf("Enter the arrival time:");
        scanf("%d",&at);
        printf("\nEnter the burst time:");
        scanf("%d",&bt);
        newnode->arrival=at;
        newnode->burst=bt;
        newnode->completion=0;
        newnode->next=NULL;
        if(start==NULL)
        {   
            start=newnode;
            start->completion=newnode->burst+newnode->arrival;
        }
        else{
            temp=start;
            while(temp->next!=NULL)
            {   
                temp=temp->next;
            }
            if((temp->completion)<(newnode->arrival))
            {
                newnode->completion=(newnode->arrival)-temp->completion+newnode->burst+temp->completion;
            }
            else newnode->completion=newnode->burst+temp->completion;
            temp->next=newnode;
        }
    }
    temp=start;
    printf("\nCompletion time:");
    int i=1;
    while(temp!=NULL)
    {
        printf("Process P%d:%d\n ",i++,temp->completion);
        temp=temp->next;
    }
   return 0;
}