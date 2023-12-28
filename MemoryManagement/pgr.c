#include<stdio.h>

int main()
{   int pageFaultCnt=0,hit=0;
    // int pages[]={7,0,1,2,0,3,0,4,2,3,0,3,2,1,2,0,1,7,0,1};
    int pages[]={0,2,1,6,4,0,1,0,3,1,2};
    int np=sizeof(pages)/sizeof(pages[0]);
    int queue[4]={0,2,1,6},i,j,k;
        for(j=0,k=0;j<np;)
        {
            for(i=0;i<4;i++)
            {
                if(pages[j]==queue[i])
                {
                    j++;
                    pageFaultCnt++;
                    hit=1;
                    break;
                }
            }
            if(hit==0)
            {
                queue[(k+1)%4]=pages[j];
                
            }
            hit=0;
        }
for(int k=0;k<4;k++)
{
    printf("%d ",queue[k]);
}
}