#include "stdio.h"
#include "stdlib.h"
#include "sys/types.h"
#include "unistd.h"

int main()
{
  pid_t child_pid;

  child_pid=fork();

  if(child_pid>0)
  {
    printf("this is the parent procsses %d sleep for a min \n",getpid() );
    sleep(60);
  }else{
    printf("this is childprocess %d exit\n",getpid() );
    exit(0);
  }
  system("ps -e -o pid,ppid,stat,cmd");
  return 0;
}
