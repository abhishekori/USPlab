
#define _POSIX_SOURCE
#define _POSIX_C_SOURCE 199309
#include<stdio.h>
#include<unistd.h>

int main(void)
{
  int res;

  if((res=sysconf(_SC_CLK_TCK))==-1)
  printf("error\n" );
  else
  printf("no of clock tics %d\n",res );

  if((res=sysconf(_SC_CHILD_MAX))==-1)
  printf("error\n" );
  else
  printf("no of child procsses %d\n", res );

  if((res=pathconf("/",_PC_PATH_MAX))==-1)
  printf("error\n" );
  else
  printf("max no of characters in a pathname %d\n",res );

  if((res=pathconf("/",_PC_NAME_MAX))==-1)
  printf("error\n" );
  else
  printf("Max no of chanracters in a file name %d\n",res );

  if((res=sysconf(_SC_OPEN_MAX))==-1)
  printf("error\n" );
  else
  printf("max no of open files %d\n",res );

  return 0;
}
