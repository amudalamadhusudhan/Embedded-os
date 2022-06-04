#include <pthread.h>
#include<stdio.h>
pthread_t tid;
void *display(void *data)
{

printf("this is a tread\n");
}
int main(int argv,char const argc[])
{
printf("before thread creation\n");
display(NULL);
printf("after the thread creation\n");
pthread_join(tid,NULL);
return 0;

}