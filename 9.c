

#include<stdio.h>

#include<sys/wait.h>

#include<errno.h>

#include<stdlib.h>

#include<unistd.h>

int sys(const char *cmdstring)
{
  pid_t pid;
  int status;

  if(cmdstring==NULL)
  return 1;

  if((pid=fork())<0)
  {
    status=-1;
  }else if(pid==0)
  {
    execl("/bin/sh","sh","-c",cmdstring,(char*)0);
    _exit(127);
  }else{
    while (waitpid(pid,&status,0)<0) {
      /* code */
      if(errno!=EINTR)
      {
        status=-1;
        break;
      }

    }
      return status;
  }

}


int main(int argc,char *argv[])
{
  int status;
  if(argc<2)
  printf("comd req\n" );
  if((status=sys(argv[1]))<0)
  exit(0);

}
