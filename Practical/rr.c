#include <stdio.h>
#include <conio.h>
void main() 
{ 
	
	int n,i,qt,count=0,temp,sq=0,bt[10],wt[10],tat[10],rem_bt[10];
	float awt=0,atat=0; 
	
	printf("Enter number of Process: ");
scanf("%d",&n);

printf("...Enter the process BT...\n");
    for (int i = 0; i < n; i++) {
        scanf("%d",&bt[i]);
        rem_bt[i]=bt[i];
    }

printf("...Enter QT...\n");
scanf("%d",&qt);

while(1)
{
	for (i = 0,count=0;i<n; i++)
	{
		temp=qt;
		if(rem_bt[i]==0)
		{
			count++;
			continue;
		}
		if(rem_bt[i]>qt)
		{
			rem_bt[i]=rem_bt[i]-qt;
		}
		else
		{
			if (rem_bt[i]>=0)
			{
				temp=rem_bt[i];
				rem_bt[i]=0;
			}
			
		}
		sq=sq+temp;
			tat[i]=sq;

	}
	if (n==count)
	{
		break;
	}
}
printf("\nFinal Result...\nProcess\tBurst time\tturnaround time\twating time\n");
    
    for (int i = 0; i < n; i++)
    {
    	wt[i]=tat[i]-bt[i];
    	awt=awt+wt[i];
    	atat=atat+tat[i];
    	printf("\n%d\t%d\t\t%d\t\t%d",i+1,bt[i],tat[i],wt[i]);
    }

    awt=awt/n;
    atat=atat/n;
    printf("\nAtat = %f",atat);
    printf("\nAwt = %f",awt);
    printf("\n-----Manan Patel-----");
getch();
}