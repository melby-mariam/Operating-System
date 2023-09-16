//LFU
#include<stdio.h>
struct que{
int val,cnt;
}q[20];
int end=0,pn,p[20];
void enqueue(int process);
int count(int po);
int small();
int frames,page_fault=0,arr;

void main(){
int n,i;
printf("Enter the number of pages : ");
scanf("%d",&n);
printf("Enter the page sequence : ");
for(i=0;i<n;i++)
scanf("%d",&p[i]);
printf("Enter the number of frames : ");
scanf("%d",&frames);
for(pn=0;pn<n;pn++)
enqueue(p[pn]);
printf("\n\nPage faults : %d",page_fault);
printf("\npage Hits : %d\n",(n-page_fault));
}

void enqueue(int process)
{
int i,j,loc=-1,s;
for(i=0;i<end;i++)
{
if(q[i].val==process)
{
loc=i;
break;
}}



if(i==end)
{
page_fault++;
if(end<frames)
{
q[end].val=process;
q[end++].cnt=count(process);
}
else
{
q[small()].val=process;
q[small()].cnt=count(process);
}}
else
{
q[i].cnt++;
}
printf("page %d :",process);
for(j=0;j<end;j++)
{
printf("%d ",q[j].val);
}
printf("\n");
}
int count(int po)
{
int c=0;
for(int i=0;i<=pn;i++)
{
if(p[i]==po)
{
c++;
}}
return c;
}
int small(){
int s=0;



for(int i=1;i<end;i++)
{
if(q[i].cnt<q[s].cnt) 
{
s=i;
}
}
return s;
}
