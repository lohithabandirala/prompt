#include<stdio.h>
int main()
{
int n,m,i,j,k;
int alloc[10][10],max[10][10],need[10][10],avail[10],finish[10]={0},safe[10],count=0;
printf("Enter number of processes and resources:");
scanf("%d%d",&n,&m);
printf("Enter Allocation Matrix:\n");
for(i=0;i<n;i++)
{
for(j=0;j<m;j++)
{
scanf("%d",&alloc[i][j]);
}
}
printf("Enter Maximum Matrix:\n");
for(i=0;i<n;i++)
{
for(j=0;j<m;j++)
{
scanf("%d",&max[i][j]);
}
}
printf("Enter Available Resources:\n");
for(j=0;j<m;j++)
{
scanf("%d",&avail[j]);
}
for(i=0;i<n;i++)
{
for(j=0;j<m;j++)
{
need[i][j]=max[i][j]-alloc[i][j];
}
}
while(count<n)
{
int found=0;
for(i=0;i<n;i++)
{
if(finish[i]==0)
{
for(j=0;j<m;j++)
{
if(need[i][j]>avail[j])
break;
}
if(j==m)
{
for(k=0;k<m;k++)
{
avail[k]+=alloc[i][k];
}
safe[count++]=i;
finish[i]=1;
found=1;
}
}
}
if(found==0)
break;
}
if(count==n)
{
printf("System is in Safe State\nSafe Sequence: ");
for(i=0;i<n;i++)
{
printf("P%d ",safe[i]);
}
}
else
{
printf("System is in Unsafe State");
}
return 0;
}