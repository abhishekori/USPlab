// VTUCS

/* Write a C/C++ program which demonstrates interprocess
communication between a reader process and a writer process. Use
mkfifo, open, read, write and close APIs in your program. */

#include<fcntl.h>

#include<sys/stat.h>

#include<sys/types.h>

#include<unistd.h>

int main()

{

int fd;

char *myfifo="/tmp/myfifo";

mkfifo(myfifo,0666);

fd=open(myfifo,O_WRONLY);

write(fd,"HELLO",sizeof("HELLO"));

close(fd);

return 0;

}
