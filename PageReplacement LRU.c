//LRU
#include<stdio.h>
struct que
{
int val,ord;
}q[20];
int s=-1,end=0;
int small();
void enqueue(int process);
int frames,page_fault=0;

void main(){
int n,i;
printf("Enter the number of pages : ");
scanf("%d",&n);
int p[n];
printf("Enter the page sequence : ");
for(i=0;i<n;i++)
scanf("%d",&p[i]);
printf("Enter the number of frames : ");
scanf("%d",&frames);
for(i=0;i<n;i++)
enqueue(p[i]);
printf("\n\nPage faults : %d",page_fault);
printf("\npage Hits : %d\n",(n-page_fault));
}

void enqueue(int process)
{
int i,j,loc=-1;
for(i=0;i<end;i++)
{
if(q[i].val==process)
{
loc=i;
break;}}




if(i==end)
{
page_fault++;
if(end<frames)
{
q[end].val=process;
q[end].ord=end+1;
end++;}
else{
s=small();
q[s].val=process;
for(i=0;i<end;i++)
{
q[i].ord--;
}
q[s].ord=end;
}
}
else{
for(j=0;j<end;j++)
{
if(q[j].ord>q[i].ord)
{
q[j].ord--; 
}}
q[i].ord=end;}
printf("page %d :",process);
for(j=0;j<end;j++)
{
printf("%d ",q[j].val);
}
printf("\n"); }
int small(){






for(int i=0;i<end;i++)
{
if(q[i].ord==1)
{
return i;
}
}}
