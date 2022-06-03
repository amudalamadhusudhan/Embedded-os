#include<stdio.h>
   #include <sys/types.h>
       #include <sys/stat.h>
       #include <fcntl.h>
        #include <unistd.h>
        #include <stdlib.h>
#define size 10*10000  
int main(int argc,char const *argv[])
{
int fd,fd1;
char buf[size];
fd=open(argv[1],O_RDONLY);
   if (fd == -1)
    {
        perror("error in open file\n");
        exit(EXIT_FAILURE);
    }
fd1=open(argv[2],O_CREAT|O_RDWR); 

while(read(fd,&buf,size))
{
    write(fd1,&buf,size);
}
return 0;

    return 0;
}