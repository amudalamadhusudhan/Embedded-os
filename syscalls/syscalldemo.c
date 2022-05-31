#include<stdio.h>
  #include <sys/types.h>
       #include <sys/stat.h>
       #include <fcntl.h>
  #include <unistd.h>
      #include <stdlib.h>


int main(int argv, char const *argc[])
{
    int fd;
    fd = open("desdlog.txt", O_CREAT | O_WRONLY);
    if (fd == -1)
    {
        perror("error in open file\n");
        exit(EXIT_FAILURE);

    }

    write(fd, "madhusudhan\n", 12);
    close(fd);
    exit(EXIT_FAILURE);

    return 0;

 }      