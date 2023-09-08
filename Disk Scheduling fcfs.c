//fcfs
#include<stdio.h>
#include<stdlib.h>

void main()
{
int head_pos,num_disk,i,seek=0,seek_time=0;
printf("Enter the head position : ");
scanf("%d",&head_pos);
printf("Enter the number of disk request : ");
scanf("%d",&num_disk);
int disk_requests[num_disk];
printf("Enter the disk requests : ");
for(i=0;i<num_disk;i++)
scanf("%d",&disk_requests[i]);	

seek=head_pos-disk_requests[0];
seek_time+=abs(seek);
printf("----\n%d\n",abs(seek));

for(i=1;i<num_disk;i++)
{
seek=disk_requests[i]-disk_requests[i-1];	
seek_time+=abs(seek);
printf("%d\n",abs(seek));
}
printf("----\n");
printf("Total Seek time : %d\n",seek_time);
}



