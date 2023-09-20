//semaphore
#include<stdio.h>
#include<stdlib.h>

int item=0;
int mutex=1;
int empty=2;
int full=0;
int wait(int s);
int signal(int s);
void producer();
void consumer();
void main()
{
int ch;
while(1)
{
printf("Enter your choice : \n");
printf("1.producer\n2.consumer\n3.Exit\n");
scanf("%d",&ch);
switch(ch)
{
case 1 : if(mutex==1&&empty!=0)
producer();
else
printf("Buffer is Full\n");
break;
case 2 : if(mutex==1&&full!=0)
consumer();
else
printf("Buffer is Empty\n");
break;
case 3 : exit(0);
break;
default : printf("Wrong choice!!!\n");


break;
}
}
}
int wait(int s)
{
return(--s); 
}
int signal(int s)
{
return(++s);
}

void producer()
{
mutex=wait(mutex);
full=signal(full);
empty=wait(empty);
item++;
printf("Producer produces the item %d\n",item);
mutex=signal(mutex);
}

void consumer()
{
mutex=wait(mutex);
full=wait(full);
empty=signal(empty);
printf("Consumer consumes the item %d\n",item);
item--;
mutex=signal(mutex);
}
