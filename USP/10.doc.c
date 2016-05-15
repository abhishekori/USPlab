// VTUCS

/* Write a C/C++ program to set up a real-time clock interval timer
using the alarm API. */

#include<signal.h>

#include<errno.h>

#include<stdio.h>

void wakeup()

{

printf("hello");

printf("------------");

}

int main()

{

struct sigaction action;

action.sa_handler=wakeup;

action.sa_flags=SA_RESTART;

sigemptyset(&action.sa_mask);

if(sigaction(SIGALRM,&action,0)==-1)

{

perror("sigaction");

}

while(1)

{

alarm(1);

pause();

printf("waiting for alarm");

}

return 0;

}

