// VTUCS

/* Write a C/C++ POSIX compliant program to check the following
limits:
(i) No. of clock ticks (ii) Max. no. of child processes
 (iii) Max. path length
(iv) Max. no. of characters in a file name (v) Max. no.
of open files/ process */

#define _POSIX_SOURCE

#define _POSIX_C_SOURCE 199309L

#include<stdio.h>

#include<unistd.h>

int main(void)

{

int res;

if((res=sysconf(_SC_CLK_TCK))==-1)

printf("doesnot support\n");

else

printf("no of clock ticks:%d\n",res);

if((res=sysconf(_SC_CHILD_MAX))==-1)

printf("doesnot support\n");

else

printf("max no of child:%d\n",res);

if((res=pathconf("/",_PC_PATH_MAX))==-1)

printf("doesnot support\n");

else

printf("max char in pathname:%d\n",res);

if((res=pathconf("/",_PC_NAME_MAX))==-1)

printf("doesnot support\n");

else

printf("max char in file name:%d\n",res);

if((res=sysconf(_SC_OPEN_MAX))==-1)

printf("doesnot support\n");

else

printf("max no of opened files:%d\n",res);

return 0;

}


