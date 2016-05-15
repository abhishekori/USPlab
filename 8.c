#include "stdio.h"
#include "stdlib.h"
#include "sys/types.h"
#include "unistd.h"
#include "sys/wait.h"

int main()
{
  pid_t pid;
  if((pid=fork())<0)
  {
    printf("fork error\n" );
  }else if(pid==0){
    printf("first childd pid= %d\n",getpid() );
    if((pid=fork())<0)
    printf("fork error\n" );
    else if(pid >0)
    exit(0);
    sleep(1);
    printf("second shild pid=%d \n parent pid %d\n",getpid(),getppid() );
    system("ps -o pid,ppid,stat,tty,cmd");
    exit(1);
  }
}
