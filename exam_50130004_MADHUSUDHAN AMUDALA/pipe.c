#include<stdio.h>
   #include <sys/types.h>
       #include <sys/stat.h>
       #include <fcntl.h>
        #include <unistd.h>
        #include <stdlib.h>

#define size 1000

int main(int argv ,char const *argc[])
{
char s[size];
pid_t id;
int fd[2]; 
int count;
char ch='s';
//fd[0] is for reading
// fd[1] for writing
  pipe(fd);
char buf[size];

  // two process
  id=fork();

  if(id==0)
  {
  //  process p2
  printf("process p2\n");
 while(read(fd[0],buf,size)!=0)
 {
   if (ch==buf)
   {
    count++;
   }
   printf("the number of letter/ character occurences of s %d\n",count);
 }
  printf("p2 receved data :\n");
  }
  else
  {
  // p1 process
   fd[1]=open("/usr/include/stdio.h",O_RDONLY);
   while(read(fd[1],&buf,size)!=0)
   {
  printf("reading the file stdio.h %s",buf);
   }
  printf("process p1 send the data\n");
  }

    return 0;
}