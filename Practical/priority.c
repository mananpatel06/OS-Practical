#include<stdio.h>
void main()
 {
   int x,n,p[10],pp[10],pt[10],w[10],t[10],e[10],a[10],i;
   float awt,atat;
   printf("Enter the number of process : ");
   scanf("%d",&n);
   printf("\n Enter process : time priorities \n");
   for(i=0;i<n;i++)
    {
      printf("\nProcess no %d : ",i+1);
      scanf("%d  %d",&pt[i],&pp[i]);
      p[i]=i+1;
      a[i]=i;
    }
    
    
    
  for(i=1;i<n-1;i++)
   {
     for(int j=i+1;j<n;j++)
     {
       if(pp[i]<pp[j])
       {
         x=pp[i];
         pp[i]=pp[j];
         pp[j]=x;
         x=pt[i];
         pt[i]=pt[j];
         pt[j]=x;
         x=p[i];
         p[i]=p[j];
         p[j]=x;
         x=a[i];
         a[i]=a[j];
         a[j]=x;
      }
   }
}
w[0]=0;
awt=0;
t[0]=pt[0];
atat=t[0];
e[0]=pt[0];
for(i=1;i<n;i++)
 {
   e[i]=e[i-1]+pt[i];
 }
int j=1;
for(i=1;i<n;i++)
 {
    t[i]=e[i]-a[i];
   atat+=t[i];
   w[i]=t[i]-pt[i];
   awt+=w[i];
 }
printf("\n\n Job \t BT \t WT \t TAT   Priority \n");
for(i=0;i<n;i++)
  printf("\n %d \t\t %d\t\t %d\t\t %d\t\t%d\n",p[i],pt[i],w[i],t[i],pp[i]);
awt=(float)awt/n;
atat=(float)atat/n;


printf("\n Average Turn Around Time : %f \n",atat);
printf("\n Average Wait Time : %f \n",awt);
printf("\n-----Manan Patel-----");
}