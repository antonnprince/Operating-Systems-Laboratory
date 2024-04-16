#include <stdio.h>


int main()
{
  
  int i,j,n,remain,ts,at[10],bt[10],wt[10],total_wt,total_tat,ts;
  int flag=0,rt[10];
  printf("Enter number of processes\n");
  scanf("%d",&n);
  remain=n;
  printf("Enter arrival and burst time for process\n");
  for(i=0;i<n;i++)
  {
      scanf("%d%d",at[i],bt[i]);
      rt[i]=bt[i];
  }
  
  printf("Enter time quantum\n");
  scanf("%d",&ts);
  
  for(time=0;i=0;remain!=0)
  {
      if(rt[i]<=ts && rt[i]>0)
      {
          time+=rt[i];
          rt[i]=0;
          flag=1;
      }
      else if(rt[i]>0)
      {
          rt[i]-=ts;
          time+=ts;
      }
      
      if(rt[i]==0 && flag==1)
      {
        remain--;
        total_wt+=time-at[i]-bt[i];
        total_tat+=wt[i]+bt[i];
        flag=0;
      }
      
      if(i==n-1)
      i=0;
      else if(at[i+1]<=time)
      i++;
      else
      i=0;
  }
    
}
