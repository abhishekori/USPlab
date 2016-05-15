// VTUCS

/* Write a C/C++ program to implement the system function */

#include<iostream>

#include<stdio.h>

#include<sys/wait.h>

#include<errno.h>

#include<stdlib.h>

#include<sys/types.h>

#include<unistd.h>

using namespace std;

int system(const char* cmd)

{

pid_t pid;

int status;

switch(pid=fork())

{

case -1:return -1;

case 0:execl("/bin/sh","sh","-c",cmd,0);
perror("execl");
exit(errno);

}

if(waitpid(pid,&status,0)==pid && WIFEXITED(status))

return WEXITSTATUS(status);

return -1;

}

int main(void)

{

int rc=0;

char buf[256];

cout<<"sh"<<endl;

if(!gets(buf));

rc=system(buf);

exit(rc);

}

