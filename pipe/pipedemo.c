

 #include <fcntl.h>  
    #include <unistd.h>
#include<stdio.h>


int main(int argv ,char const *argc[])
{
char s[12];
pid_t id;
int fd[2]; 
//fd[0] is for reading
// fd[1] for writing
  pipe(fd);

  // two process
  id=fork();

  if(id==0)
  {
  // child process
  printf("childprocess\n");
  read(fd[0],s,sizeof(s));
  printf("child receved data :%s\n",s);
  }
  else
  {
  // parent process
  printf("parent process\n");
  write(fd[1],"madhusudhan\n",12);
  printf("parent wrote data\n");
  }

    return 0;
}