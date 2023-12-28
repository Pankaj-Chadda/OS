#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
void sort(int left[],int n)
{
    int i=0,j;
    for(i=1;i<n;i++)
    {
        int temp=left[i];
        int j=i-1;
        while(j>=0 && left[j]>temp)
        {
            left[j+1]=left[j];
           j--;
        }
        left[j+1]=temp;
    }
    printf("\nSorted:");
    for(i=0;i<n;i++)
    {
        printf("%d ",left[i]);
    }
    printf("\n");
}
int min_element(int request_queue[],int n)
{
    int min = INT_MAX;
    for(int i=0;i<n;i++)
    {
       if(request_queue[i] < min)
          min = request_queue[i];
    }
    return min;  
}
int max_element(int request_queue[],int n)
{
   int max = INT_MIN;
   for(int i=0;i<n;i++)
   {
      if(request_queue[i] > max)
          max = request_queue[i];
   }
    return max;  
}
int applySCANAlgo(int total_cylinders,int request_queue[], int initial_pos, int seek_sequence[], int direction,int *sequence_size,int n)
{
	int total_head_movement=0,j=0,k=0;
	int left[n+1], right[n+1];  
	if(direction == 0)
    {
        if(initial_pos > min_element(request_queue,n))
     		right[j++]=total_cylinders-1;
        right[j++]=initial_pos;
        left[k++]=0;
    }
    else if(direction == 1)
    {
        if(initial_pos < max_element(request_queue,n))
		   left[k++]=0;  
        left[k++]=initial_pos;
        right[j++]=total_cylinders-1;
    }
   
    
	for (int i = 0; i<n; i++) {
		if (request_queue[i] < initial_pos)
			left[k++]=request_queue[i];
		if (request_queue[i] > initial_pos)
			right[j++]=request_queue[i];
	}
    sort(left,k);
    sort(right,j);
    int completed = 2;
	while (completed--)
    {
        if (direction == 0) 
        {
			for (int i = 0; i<j; i++) 
            {
                total_head_movement += abs(initial_pos - right[i]);	
                initial_pos = right[i];
                seek_sequence[*sequence_size]=right[i]; 
                (*sequence_size)++;
               
            }
            direction = 1;
		}
        else if (direction == 1)
        {
			for (int i =0; i<k; i++) 
            {
				total_head_movement +=  abs(initial_pos - left[i]);	
                initial_pos = left[i];
                seek_sequence[*sequence_size]=left[i]; 
                (*sequence_size)++;
            }
            direction = 0;
		}
	}  
    return total_head_movement;
} 

int main()
{
    int total_cylinders,total_head_movement=0,initial_pos,n,direction,pos;
    printf("\nEnter the total no. of cylinders in HDD:\n");
    scanf("%d",&total_cylinders);
    printf("\nEnter the no. of cylinders to enter in Request queue:\n");
    scanf("%d",&n);
    int request_queue[n];
    int seek_sequence[n+10];   // i.e take somewhat bigger size than n
    int sequence_size=0;
    printf("\nEnter the cylinders no. in Request queue :\n");
    for(int i=0;i<n;i++)
     scanf("%d",&request_queue[i]);
    printf("\nEnter the initial Position of RW head: ");
    scanf("%d",&initial_pos);
    printf("\nEnter the direction in which Read Write head is moving:\n ");
    printf("\nEnter 0 if moving to higher cylinder else Enter 1: ");
    scanf("%d",&direction);

    if(initial_pos < 0 || initial_pos > total_cylinders - 1)
    {
        printf("Wrong Initial Position Enetered !!");
        exit(0);
    }
    total_head_movement = applySCANAlgo(total_cylinders,request_queue,initial_pos,seek_sequence,direction,&sequence_size,n);
    printf("\n\n*********** OUTPUT **********");
    printf("\nSeek Sequence: ");
    for(int i=0;i<sequence_size;i++)
    printf("%d ",seek_sequence[i]);
    printf("\nTotal No. of Head Movements = %d\n",total_head_movement);
    printf("\nAverage head movements = %.2f\n\n",(float)total_head_movement/n);
return 0;
}