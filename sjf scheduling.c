//sjf scheduling

#include<stdio.h>
struct process
{
int p,bt,ct,tat,wt;
};
void main()
{
int n,i,j;
float total_tat,total_wt,current_ct=0;
printf("Enter the number of processes : ");
scanf("%d",&n);	
struct process p[n];
for(i=0;i<n;i++)
{
printf("Enter the burst time of P%d : ",i);
scanf("%d",&p[i].bt);
p[i].p=i;
}
for(i=0;i<n;i++)
{
for(j=0;j<n-i-1;j++)
{
if(p[j].bt>p[j+1].bt)
{
struct process temp=p[j];
p[j]=p[j+1];
p[j+1]=temp;
}
}
}
printf("Gantt Chart\n");
printf("--------------------------------------------------\n|");
for(i=0;i<n;i++)



{
printf("P%d\t|",p[i].p);
current_ct+=p[i].bt;
p[i].ct=current_ct;
p[i].tat=p[i].ct;
p[i].wt=p[i].tat-p[i].bt;
}
printf("\n-------------------------------------------------\n0\t");
for(i=0;i<n;i++)
{
printf("%d\t",p[i].ct);
total_tat+=p[i].tat;
total_wt+=p[i].wt;
}
printf("\n");
for(i=0;i<n;i++)
{
for(j=0;j<n-i-1;j++)
{
if(p[j].p>p[j+1].p)
{
struct process temp=p[j];
p[j]=p[j+1];
p[j+1]=temp;
}
}
}
printf("\n  Turnaround time\tWaiting time\n");
for(i=0;i<n;i++)
{
printf("P%d\t%d\t\t%d\n",p[i].p,p[i].tat,p[i].wt);
}
printf("\nTotal Turnaround time : %f",total_tat);
printf("\nTotal Waiting time : %f",total_wt);
printf("\nAverage Turnaround time : %f",total_tat/n);
printf("\nAverage Waiting time : %f",total_wt/n);
}
