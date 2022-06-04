#include <pthread.h>
#include<stdio.h>
pthread_t tid;
pthread_attr_t attr;
void *display(void *data)
{

printf("this is a tread\n");
}
int main(int argv,char const argc[])
{
    pthread_attr_init(&attr);

pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_DETACHED);

printf("before thread creation\n");
pthread_create(&tid,NULL,display,NULL);
pthread_attr_destroy(&attr); //delocate resources 
printf("after the thread creation\n");
pthread_join(tid,NULL); //WAIT UNTILL display thread completed
return 0;



}