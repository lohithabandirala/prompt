
#include<stdio.h>
int main()
{
int n,i,at[20],bt[20],rt[20],ct[20],tat[20],wt[20],time=0,count=0,quantum,flag;
float avgwt=0,avgtat=0;
printf("Enter number of processes:");
scanf("%d",&n);
for(i=0;i<n;i++)
{
printf("Enter AT and BT:");
scanf("%d%d",&at[i],&bt[i]);
rt[i]=bt[i];
}
printf("Enter Time Quantum:");
scanf("%d",&quantum);
while(count<n)
{
flag=0;
for(i=0;i<n;i++)
{
if(at[i]<=time && rt[i]>0)
{
flag=1;
if(rt[i]>quantum)
{
time+=quantum;
rt[i]-=quantum;
}
else
{
time+=rt[i];
rt[i]=0;
ct[i]=time;
tat[i]=ct[i]-at[i];
wt[i]=tat[i]-bt[i];
avgwt+=wt[i];
avgtat+=tat[i];
count++;
}
}
}
if(flag==0)
time++;
}
printf("\nP\tAT\tBT\tCT\tTAT\tWT\n");
for(i=0;i<n;i++)
printf("P%d\t%d\t%d\t%d\t%d\t%d\n",i+1,at[i],bt[i],ct[i],tat[i],wt[i]);
printf("Average TAT=%.2f\nAverage WT=%.2f",avgtat/n,avgwt/n);
return 0;
}
