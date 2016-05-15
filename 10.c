#include "stdio.h"
#include "unistd.h"
#include "signal.h"
#define INTERVAL 5

void callme(int sig_no)
{
  alarm(INTERVAL);
  printf("call handler\n" );
}

int main()
{
  struct sigaction action;
  sigemptyset(&action.sa_mask);
  action.sa_handler=(void(*)())callme;
  action.sa_flags=SA_RESTART;

  if(sigaction(SIGALRM,&action,0)==-1)
  {
    perror("sigaction");
    return 1;

  }
  if(alarm(INTERVAL)==-1)
  perror("alarm");
  else{
//sleep(10);
    printf("alarm executed\n" );
  }

  while(1)
  {
  alarm(5);
  pause();
  printf("Waiting For Alarm\n");
  }
  return 0;


}
