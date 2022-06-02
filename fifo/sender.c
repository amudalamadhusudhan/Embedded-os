#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
  #include <unistd.h>
  
int main(int argc, char const *argv[])
{
int fd;
fd =open("desdfifo",O_RDWR);

write(fd,"madhsudhan\n",12);


close(fd);

return 0;



}