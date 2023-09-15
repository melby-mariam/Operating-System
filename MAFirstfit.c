//First fit
#include<stdio.h>
void main()
{
int n1,n2,i,j;
printf("Enter the number of blocks : ");
scanf("%d",&n1);
printf("Enter the no.of jobs : ");
scanf("%d",&n2);
int a[n1],b[n2],vis[n2],c[n1];
printf("Enter the size of the blocks : ");
for(i=0;i<n1;i++)
{
scanf("%d",&a[i]);
c[i]=a[i];
}
printf("Enter the size of the processes : ");
for(i=0;i<n2;i++)
{
vis[i]=0;
scanf("%d",&b[i]);
}
for(i=0;i<n2;i++)
{
for(j=0;j<n1;j++)
{
if(a[j]>=b[i])
{
vis[i]=a[j];
a[j]=a[j]-b[i];
break;
}
}



}
printf("\nSTATUS\n");
for(i=0;i<n2;i++)
{
if(vis[i]==0)
{
printf("%d is waiting\n",b[i]);
}
else
{
printf("%d is inserted in %d block\n",b[i],vis[i]);
}
}
}

