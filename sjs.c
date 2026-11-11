
#include<stdio.h>
int main()
{
int n,i,j,t,at[20],bt[20],ct[20],tat[20],wt[20],p[20],done[20]={0},time=0,count=0,k;
float avgwt=0,avgtat=0;
printf("Enter number of processes:");
scanf("%d",&n);
for(i=0;i<n;i++)
{
p[i]=i+1;
printf("Enter AT and BT:");
scanf("%d%d",&at[i],&bt[i]);
}
while(count<n)
{
k=-1;
for(i=0;i<n;i++)
if(!done[i] && at[i]<=time && (k==-1 || bt[i]<bt[k]))
k=i;
if(k==-1)
{
time++;
continue;
}
time+=bt[k];
ct[k]=time;
tat[k]=ct[k]-at[k];
wt[k]=tat[k]-bt[k];
avgwt+=wt[k];
avgtat+=tat[k];
done[k]=1;
count++;
}
printf("\nP\tAT\tBT\tCT\tTAT\tWT\n");
for(i=0;i<n;i++)
printf("P%d\t%d\t%d\t%d\t%d\t%d\n",p[i],at[i],bt[i],ct[i],tat[i],wt[i]);
printf("Average TAT=%.2f\nAverage WT=%.2f",avgtat/n,avgwt/n);
return 0;
}
