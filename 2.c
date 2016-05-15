#define _POSIX_SOURCE
#define _POSIX_C_SOURCE 1099309L

#include "stdio.h"
#include "unistd.h"

int main()
{

  #ifdef _POSIX_JOB_CONTROL
  printf("yes\n" );
  #else
  printf("no\n");
  #endif

  #ifdef _POSIX_SAVED_IDS
  printf("yes\n" );
  #else
  printf("np\n" );
 #endif

  #ifdef _POSIX_CHOWN_RESTRICTED
  printf("yes\n" );
  #else
  printf("no\n" );
  #endif

  #ifdef _POSIX_NO_TRUNC
  printf("yes\n" );
  #else
  printf("no\n" );
  #endif

  #ifdef _POSIX_VDISABLE
  printf("yes\n" );
  #else
  printf("no\n" );
  #endif

}
