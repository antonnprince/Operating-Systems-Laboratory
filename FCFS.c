#include <stdio.h>

struct process {
    int at,bt,tat,pid,wt;

};

int main()
{
   int total_tat,total_wt;
   struct process p[10],temp;
   int n,i,j,sum;
   
   printf("Enter the number of process\n");
   scanf("%d",&n);
   for(i=0;i<n;i++)
   {
       printf("Enter arrival and brust time for process %d", i+1);
       scanf("%d %d",&p[i].at, &p[i].bt);
       p[i].pid=i+1;
   }
   
   for(i=0;i<n;i++)
   {
       for(j=0;j<n-i-1;j++)
       {
           if(p[j].at>p[j+1].at)
           {
               temp=p[j];
               p[j]=p[j+1];
               p[j+1]=temp;
           }
       }
   }
   
   //calculating turn around time
   for(i=0;i<n;i++)
   {
    sum=sum+p[i].bt;
    p[i].tat=sum;
   }
   sum=0;
   //calculating wait time
   for(i=0;i<n;i++)
   {
       sum=p[i].tat-p[i].bt;
       p[i].wt=sum;
   }
   
   printf("Process-ID\t Arrival Time\t Burst Time\t Wait Time\t Turn Around Time\t");
   for(i=0;i<n;i++)
   {
       printf("\n %d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t", p[i].pid,p[i].at, p[i].bt, p[i].wt, p[i].tat);
       
   }
   
   

    return 0;
}

