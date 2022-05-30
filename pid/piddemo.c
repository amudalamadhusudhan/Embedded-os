#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>


int main(int argc,char const *argv[])
{
 pid_t pid;
 pid_t ppid;

 pid=getpid();
printf("process pid:%d\n",pid);
  ppid=getppid();
  printf("process parent id ppid:%d\n",ppid);
return 0;
}