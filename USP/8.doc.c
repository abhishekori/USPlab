// VTUCS

/* Write a C/C++ program to avoid zombie process by forking twice. */

#include<stdio.h>

#include<stdlib.h>

#include<errno.h>

#include<sys/wait.h>

int main(void)

{

pid_t pid;

if((pid=fork())<0)

{

printf("\n fork error");

}

else if(pid==0)

{

if((pid=fork())<0)

printf("fork error");

else if(pid>0)

exit(0);

sleep(2);

printf("\nsecond child parent pid=%d\n",getppid());

exit(0);

}

if(waitpid(pid,NULL,0)!=pid)

priintf("waitpid error");

exit(0);

}
