// VTUCS

/* Write a C/C++ program that creates a zombie and then calls system
to execute the ps command to verify that the process is zombie. */

#include<stdlib.h>

#include<stdio.h>

#include<unistd.h>

#include<sys/types.h>

int main(void)

{

pid_t child_pid;

child_pid=fork();

if(child_pid==0)

{

exit(0);

}

else

{

sleep(2);

system("ps -e -o pid,ppid,stat,cmd");

}

return 0;

}
