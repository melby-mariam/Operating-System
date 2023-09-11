//fcfs scheduling
#include<stdio.h>

float avg(int a[],int n) {
float t=0;
for(int i=0;i<n;i++) {
t=t+a[i];
}
return t/n;
}

int total(int a[],int n) {
int t=0;
for(int i=0;i<n;i++) {
t=t+a[i];
}
return t;
}

void main() {
int n,i;
printf("Enter the no.of Processes: ");
scanf("%d",&n);
int bt[n],ct[n],tat[n],wt[n],at[n];

//Entering Burst time
printf("Enter the Burst time:\n");
for(i=0;i<n;i++) {
printf("P%d: ",i);
scanf("%d",&bt[i]);
at[i]=0;
ct[i]=0;
}




//Calculating Completion time
ct[-1]=0;
for(i=0;i<n;i++) {
ct[i]=ct[i-1]+bt[i]; }

//Displaying GANTT CHART
printf("\n\n GANTT CHART\n");
 printf("---------------------------------\n");
printf("| ");
for(i=0;i<n;i++) {
printf("%d|\t",ct[i]);
}
printf("\n---------------------------------");
for(i=0;i<n;i++) {
if(i==0) {
printf("\n%d\t%d\t",0,ct[i]);
}
else {
printf("%d\t",ct[i]);
}
}

//Calculating Turn Around Time
for(i=0;i<n;i++) {
tat[i]=ct[i]-at[i];
}

//Calculating Waiting Time
for(i=0;i<n;i++) {
wt[i]=tat[i]-bt[i];
}

//TABLE
printf("\n\nProcess\tBT\tTAT\tWT");
for(i=0;i<n;i++) {
printf("\nP%d\t%d \t%d \t%d",i,bt[i],tat[i],wt[i]);
}




printf("\n\nTotal Turn Around Time: %d",total(tat,n));
printf("\nTotal Waiting Time: %d",total(wt,n));
printf("\n\nAverage of Turn Around Time: %f",avg(tat,n));
printf("\nAverage of Waiting Time: %f\n",avg(wt,n)); }

