// VTUCS

/* Write a C/C++ program which demonstrates interprocess
communication between a reader process and a writer process. Use
mkfifo, open, read, write and close APIs in your program. */

#include<stdio.h>

#include<sys/stat.h>

#include<unistd.h>

#include<sys/types.h>

#include<fcntl.h>

#define MAX_BUF 1024
int main(void)

{

int fd;

char *myfifo="/tmp/myfifo";

char buf[MAX_BUF];

fd=open(myfifo,O_RDONLY);

read(fd,buf,MAX_BUF);

printf("Recieved:%s",buf);

close(fd);

return 0;

}
