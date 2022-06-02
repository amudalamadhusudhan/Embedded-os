#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
  #include <unistd.h>
  
int main(int argc, char const *argv[])
{
int fd;
char s[12];
fd =open("desdfifo",O_RDONLY);

read(fd,s,12);
printf("read data :%s\n" ,s);


close(fd);

return 0;
}

