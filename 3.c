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
    perror("cant open the file\n" );
    exit(1);
  }

  if(fcntl(fd,F_SETLK,&f1)==-1)
  {
    perror("cant set exclusive lock");
    exit(1);
  }else if(f1.l_type!=F_UNLCK)
  {
    printf("it has been locked\n" );

  }else{
    printf("its not locked\n" );
  }

  printf("Please enter to unlock" );
  getchar();
  f1.l_type=F_UNLCK;
  lseek(fd,-100,SEEK_END);

  lseek(fd,50,SEEK_CUR);

  read(fd,buf,50);

  printf("last 50bytes contents is\n");

  printf("%s",buf);
  return 0;
}
