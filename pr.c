
#include<stdio.h>
int main()
{
int n,i,at[20],bt[20],pr[20],rt[20],ct[20],tat[20],wt[20],time=0,count=0,k;
float avgwt=0,avgtat=0;
printf("Enter number of processes:");
scanf("%d",&n);
for(i=0;i<n;i++)
{
printf("Enter AT, BT and Priority:");
scanf("%d%d%d",&at[i],&bt[i],&pr[i]);
rt[i]=bt[i];
}
while(count<n)
{
k=-1;
for(i=0;i<n;i++)
{
if(at[i]<=time && rt[i]>0 && (k==-1 || pr[i]<pr[k]))
k=i;
}
if(k==-1)
{
time++;
continue;
}
rt[k]--;
time++;
if(rt[k]==0)
{
ct[k]=time;
tat[k]=ct[k]-at[k];
wt[k]=tat[k]-bt[k];
avgwt+=wt[k];
avgtat+=tat[k];
count++;
}
}
printf("\nP\tAT\tBT\tPR\tCT\tTAT\tWT\n");
for(i=0;i<n;i++)
printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",i+1,at[i],bt[i],pr[i],ct[i],tat[i],wt[i]);
printf("Average TAT=%.2f\nAverage WT=%.2f",avgtat/n,avgwt/n);
return 0;
}
