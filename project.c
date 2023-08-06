#include<stdio.h>
 int main()
{
    int i,j,k,temp, n = 5, sum=0, sum2=0;
    int BT[n],WT[n],TT[n];
    int p[5] = {1,2,3,4,5};
    printf("Shortest Job First (SJF) Algorithm\n");
    printf("Enter the Burst Time for 5 Processes:\n");
    for(int i=0; i<n; i++)
      scanf("%d",&BT[i]);
      
   //sorting of burst times
    for(i=0;i<n;i++)
    {
        k=i;
        for(j=i+1;j<n;j++)
        {
            if(BT[j]<BT[k])
                k=j;
        }
  
        temp=BT[i];
        BT[i]=BT[k];
        BT[k]=temp;
  
        temp=p[i];
        p[i]=p[k];
        p[k]=temp;
    }
   
    for(i=0;i<n;i++)
    {
        WT[i]=0;
        for(j=0;j<i;j++)
            WT[i]+=BT[j];
  
        sum+=WT[i];
    }
 
    printf("\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time");
    for(i=0;i<n;i++)
    {
        TT[i]=BT[i]+WT[i];   
        sum2+=TT[i];
        printf("\np%d\t\t  %d\t\t    %d\t\t\t%d",p[i],BT[i],WT[i],TT[i]);
    }
    
    printf("\nAverage Waiting Time= %f ",(float)sum/n);
    printf("\nAverage Turnaround Time= %f ",(float)sum2/n);
}