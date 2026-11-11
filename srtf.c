
#include<stdio.h>
int main()
{
int n,i,at[20],bt[20],rt[20],ct[20],tat[20],wt[20],time=0,count=0,k,min;
float avgwt=0,avgtat=0;
printf("Enter number of processes:");
scanf("%d",&n);
for(i=0;i<n;i++)
{
printf("Enter AT and BT:");
scanf("%d%d",&at[i],&bt[i]);
rt[i]=bt[i];
}
while(count<n)
{
k=-1;
min=9999;
for(i=0;i<n;i++)
{
if(at[i]<=time && rt[i]>0 && rt[i]<min)
{
min=rt[i];
k=i;
}
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
printf("\nP\tAT\tBT\tCT\tTAT\tWT\n");
for(i=0;i<n;i++)
printf("P%d\t%d\t%d\t%d\t%d\t%d\n",i+1,at[i],bt[i],ct[i],tat[i],wt[i]);
printf("Average TAT=%.2f\nAverage WT=%.2f",avgtat/n,avgwt/n);
return 0;
}
