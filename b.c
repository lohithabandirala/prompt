#include<stdio.h>
int main()
{
int n,m,i,j,p;
int alloc[10][10],max[10][10],need[10][10],avail[10],req[10];
int finish[10]={0},safe[10],count;
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
printf("Enter process number:");
scanf("%d",&p);
printf("Enter request resources:\n");
for(j=0;j<m;j++)
{
scanf("%d",&req[j]);
}
for(i=0;i<n;i++)
{
for(j=0;j<m;j++)
{
need[i][j]=max[i][j]-alloc[i][j];
}
}
for(j=0;j<m;j++)
{
if(req[j]>need[p][j])
{
printf("Error: Request exceeds need");
return 0;
}
}
for(j=0;j<m;j++)
{
if(req[j]>avail[j])
{
printf("Resources not available");
return 0;
}
}
for(j=0;j<m;j++)
{
avail[j]-=req[j];
alloc[p][j]+=req[j];
need[p][j]-=req[j];
}
count=0;
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
for(j=0;j<m;j++)
{
avail[j]+=alloc[i][j];
}
safe[count++]=i;
finish[i]=1;
found=1;
}
}
}
if(!found)
break;
}
if(count==n)
{
printf("Request Granted\nSafe Sequence: ");
for(i=0;i<n;i++)
{
printf("P%d ",safe[i]);
}
}
else
{
printf("Request Denied: Unsafe State");
}
return 0;
}