#include<stdio.h>
 
 int main()
 
{
    int n,bt[20],wt[20],tat[20],i,j,et[20];
    double avwt,avtat;
    printf("Enter total number of processes");
    scanf("%d",&n);
 
    printf("\nEnter Process Burst Time\n");
    for(i=0;i<n;i++)
    {
        printf("P[%d]:",i+1);
        scanf("%d",&bt[i]);
    }
 
    et[0]=bt[0];   
 
    for(i=1;i<n;i++)
    {
            et[i]=et[i-1]+bt[i];
    }
 
    printf("\nProcess\tAT\tBT\t\tWT\tTAT");
 
    for(i=0;i<n;i++)
    {
        tat[i]=et[i]-i;
        wt[i]=tat[i]-bt[i];
        avwt+=wt[i];
        avtat+=tat[i];
        printf("\nP[%d]\t%d\t%d\t\t%d\t\t%d",i+1,i,bt[i],wt[i],tat[i]);
    }
 
   avwt=((double)avwt/i);
    avtat=(double)avtat/i;
    printf("\n\nAverage Waiting Time:%f",avwt);
    printf("\nAverage Turnaround Time:%f",avtat);
 
    printf("\n-------Manan Patel----------\n");

    return 0;
}


