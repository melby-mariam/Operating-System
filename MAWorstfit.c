//Worstfit
#include<stdio.h>
#include<stdlib.h>

int n1,n2,a[20],b[20];
int findblock(int x);
void main()
{
int i,j;
printf("Enter number of blocks : ");
scanf("%d",&n1);
int c[n1];
printf("Enter the number of jobs : ");
scanf("%d",&n2);
int vis[n2];
printf("Enter the size of the blocks : ");
for(i=0;i<n1;i++)
{
scanf("%d",&a[i]);



c[i]=a[i];
}
printf("Enter the size of the jobs : ");
for(i=0;i<n2;i++)
{
scanf("%d",&b[i]);
vis[i]=0;
}
for(i=0;i<n2;i++)
{
j=findblock(b[i]);    
if(j!=100)
{
vis[i]=c[j];
a[j]=a[j]-b[i];
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
printf("%d is inserted into block %d\n",b[i],vis[i]);    
}    
}
}

int findblock(int x)
{
int found=0,index,largest=0,i;
for(i=0;i<n1;i++)
{
if(a[i]>=x)
{



if(a[i]>largest)
{
found=1;
index=i;
largest=a[i];
}
}
}
if(found==0)
return 100;
else
return index;
}

