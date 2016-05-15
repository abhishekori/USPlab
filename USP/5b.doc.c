// VTUCS

/* Write a C / C++ program to emulate the unix ln command */

#include<stdio.h>

#include<sys/types.h>

#include<unistd.h>

#include<string.h>

int main(int argc,char *argv[])

{

if((argc<3 || argc>4) || (argc==4 && strcmp(argv[1],"-s")))

{

printf("enter properly\n");

return 1;

}

if(argc==4)

{
printf("Symbolic link created\n");

return symlink(argv[2],argv[3]);

}

else

{

printf("hard link created\n");

return link(argv[1],argv[2]);

}

return 0;

}
 

