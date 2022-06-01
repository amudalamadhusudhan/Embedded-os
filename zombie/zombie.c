 #include <sys/types.h>
          #include <unistd.h>
                 #include<stdio.h>

  int main(int argv ,char const *argc[])
{
 pid_t id;
 printf("before fork\n");
 id=fork();
 if(id==0)
 {
 printf("child process ID : %d PPID :%d\n",getpid(),getppid());
 printf("child is completed\n");
 }
 else if(id>0)
 {
 printf("parent process ID: %d PPID: %d\n",getpid(),getppid());
  sleep(10);
  printf("parent completed\n");
 }
 else
 {
 perror("fork failed\n");
 }

return 0;

 }