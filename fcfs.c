
#include<stdio.h>
int main()
{
int n,i,j,t,at[20],bt[20],ct[20],tat[20],wt[20],p[20],time=0;
float avgwt=0,avgtat=0;
printf("Enter number of processes:");
scanf("%d",&n);
for(i=0;i<n;i++)
{
p[i]=i+1;
printf("Enter AT and BT:");
scanf("%d%d",&at[i],&bt[i]);
}
for(i=0;i<n;i++)
for(j=i+1;j<n;j++)
if(at[i]>at[j])
{
t=at[i];at[i]=at[j];at[j]=t;
t=bt[i];bt[i]=bt[j];bt[j]=t;
t=p[i];p[i]=p[j];p[j]=t;
}
for(i=0;i<n;i++)
{
if(time<at[i]) time=at[i];
ct[i]=time+bt[i];
time=ct[i];
tat[i]=ct[i]-at[i];
wt[i]=tat[i]-bt[i];
avgtat+=tat[i];
avgwt+=wt[i];
}
printf("\nP\tAT\tBT\tCT\tTAT\tWT\n");
for(i=0;i<n;i++)
printf("P%d\t%d\t%d\t%d\t%d\t%d\n",p[i],at[i],bt[i],ct[i],tat[i],wt[i]);
printf("Average TAT=%.2f\nAverage WT=%.2f",avgtat/n,avgwt/n);
return 0;
}
