//fifo
#include<stdio.h>
int queue[20];
int rear=-1;
int frames,count=0,page_fault=0;
void enqueue(int process){
int i,j;
if(count!=frames)
{
rear=(rear+1)%frames;
queue[rear]=process;
count++;
printf("Fault ");
for(i=0;i<count;i++)
printf("%d ",queue[i]);
printf("\n");
page_fault++;
}
else
{
for(i=0;i<frames;i++)
{




if(queue[i]==process)
{
printf("Hit ");
for(j=0;j<frames;j++)
printf("%d ",queue[j]);
printf("\n");
return;
}
}
rear=(rear+1)%frames;
queue[rear]=process;
printf("Fault ");
for(j=0;j<frames;j++)
printf("%d ",queue[j]);
printf("\n");
page_fault++;
}}
void main(){
int n,i;
printf("Enter the number of Referenced strings : ");
scanf("%d",&n);
int pro[n];
printf("Enter the referenced strings : ");


for(i=0;i<n;i++)
scanf("%d",&pro[i]);
printf("Enter the number of frames : ");
scanf("%d",&frames);
for(i=0;i<n;i++){
enqueue(pro[i]);}
printf("\n\nPage fault : %d",page_fault);
}

