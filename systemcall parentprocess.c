//parent process
#include<sys/types.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>
int main() {

int id=fork();

if(id>0) {
wait(NULL);
printf("\nParent");
printf("%d",getpid());
}
else if(id==0) {
printf("\nChild");
printf("\nChild%d",getpid());
printf("\nParent%d",getppid());
}
else {
printf("Error");
}

printf("Exiting function");
exit(0);
printf("Exit is not executing");
return 0;
}
