
  #include <sys/types.h>
       #include <unistd.h>
#include<stdio.h>

int main(int argv ,char const *argc[])
{
 pid_t id;

 printf("before fork\n");
 id=fork();
 printf("after fork\n");
 
 
return 0;

 }
