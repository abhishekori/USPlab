#include "stdio.h"
#include "unistd.h"

int main(int argc,char* argv[])
{
  if(argc!=3)
  {
    printf("Error\n" );
    return 0;
  }

  if((link(argv[1],argv[2]))==-1)
  {
    printf("error\n" );
    return 1;
  }

  return 0;

}
