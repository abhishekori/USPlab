// VTUCS

/* Write a C/C++ POSIX compliant program that prints the POSIX
defined configuration options supported on any given system using
feature test macros. */

#define _POSIX_SOURCE

#define _POSIX_C_SOURCE 199309L

#include<stdio.h>
#include<unistd.h>

int main(void)

{

#ifdef _POSIX_JOB_CONTROL

printf("System supports\n");

#else

printf("System supports JC\n");

#endif

#ifdef _POSIX_SAVED_IDS

printf("System supports\n");

#else

printf("System supports saved setUID and setGID\n");

#endif

#ifdef _POSIX_CHOWN_RESTRICTED

printf("System supports\n");

printf("%d\n",_POSIX_CHOWN_RESTRICTED);

#else
printf("System doesnot supports\n");

#endif

#ifdef _POSIX_NO_TRUNC

printf("System supports\n");

printf("%d\n",_POSIX_NO_TRUNC);

#else
printf("System doesnot supports\n");

#endif

#ifdef _POSIX_VDISABLE

printf("System supports\n");

printf("%d\n",_POSIX_VDISABLE);

#else

printf("System doesnot supports\n");

#endif

return 0;

}

