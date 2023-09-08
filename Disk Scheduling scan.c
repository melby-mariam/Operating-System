//scan
#include<stdio.h>
#include<stdlib.h>

void main()
{
int head_pos,num_disk,i,seek=0,seek_time=0,j,mid=0;
printf("Enter the head position : ");
scanf("%d",&head_pos);
printf("Enter the number of disk request : ");
scanf("%d",&num_disk);
int disk_requests[num_disk];
printf("Enter the disk requests : ");
for(i=0;i<num_disk;i++)
scanf("%d",&disk_requests[i]);




for(i=0;i<num_disk;i++)
{
for(j=0;j<num_disk-i-1;j++)
{
if(disk_requests[j]>disk_requests[j+1])
{
int temp=disk_requests[j];
disk_requests[j]=disk_requests[j+1];
disk_requests[j+1]=temp;
}
}
}

for(i=0;i<num_disk;i++)
{
if(disk_requests[i]>head_pos)
{
mid=i;
break;
}
}
seek=head_pos-disk_requests[mid-1];
seek_time+=abs(seek);
printf("----\n%d\n",abs(seek));
for(i=mid-1;i>=0;i--)
{
if(i==0)
{
seek=disk_requests[i];	
}
else
{
seek=disk_requests[i]-disk_requests[i-1];
}
printf("%d\n",abs(seek));





seek_time+=abs(seek);
}
for(i=mid;i<num_disk;i++)
{
if(i==mid)
{
seek=0-disk_requests[i];
}
else
{
seek=disk_requests[i-1]-disk_requests[i];
}
printf("%d\n",abs(seek));
seek_time+=abs(seek);
}
printf("----\n");
printf("Total Seek time : %d\n",seek_time);
}

