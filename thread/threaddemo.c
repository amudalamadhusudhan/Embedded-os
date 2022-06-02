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
pthread_create(&tid,NULL,display,NULL);
sleep(1);
printf("after the thread creation\n");
return 0;



}