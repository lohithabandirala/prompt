
#include<stdio.h>

int main()
{
    int a[20],g[10],n,m,i,j;

    printf("Enter data size: ");
    scanf("%d",&n);

    printf("Enter data: ");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);

    printf("Enter generator size: ");
    scanf("%d",&m);

    printf("Enter generator: ");
    for(i=0;i<m;i++)
        scanf("%d",&g[i]);

    for(i=n;i<n+m-1;i++)
        a[i]=0;

    // Sender
    for(i=0;i<n;i++)
        if(a[i]==1)
            for(j=0;j<m;j++)
                a[i+j]^=g[j];

    printf("CRC: ");
    for(i=n;i<n+m-1;i++)
        printf("%d",a[i]);

    printf("\nEnter received data: ");
    for(i=0;i<n+m-1;i++)
        scanf("%d",&a[i]);

    // Receiver
    for(i=0;i<n;i++)
        if(a[i]==1)
            for(j=0;j<m;j++)
                a[i+j]^=g[j];

    for(i=n;i<n+m-1;i++)
        if(a[i]!=0)
        {
            printf("Error detected");
            return 0;
        }

    printf("No error detected");
    return 0;
}
