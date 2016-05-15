// VTUCS

/* Consider the last 100 bytes as a region. Write a C/C++ program to
check whether the region is locked or not. If the region is locked,
print pid of the process which has locked. If the region is not locked,
lock the region with an exclusive lock, read the last 50 bytes and
unlock the region. */

#include<stdio.h>

#include<stdlib.h>

#include<fcntl.h>

#include<unistd.h>

#include<errno.h>

int main(int argc,char *argv[])

{

struct flock f1={F_WRLCK,SEEK_SET,0,100,0};

int fd;

char buf[50];

f1.l_pid=getpid();

if((fd=open(argv[1],O_RDWR))==-1)

{

perror("cant open file\n");

exit(1);

}

if(fcntl(fd,F_SETLK,&f1)==-1)

{

perror("cant set exclusive lock\n");

exit(1);

}

else if(f1.l_type!=F_UNLCK)

{

printf("file exclusively locked by process %d",f1.l_pid);

}

else

{

printf("file is not locked\n");

}

printf("press enter key to release lock\n");

getchar();

f1.l_type=F_UNLCK;

printf("file has been unlocked\n");

lseek(fd,-100,SEEK_END);

lseek(fd,50,SEEK_CUR);

read(fd,buf,50);

printf("last 50bytes contents is\n");

printf("%s",buf);

return 0;

}
