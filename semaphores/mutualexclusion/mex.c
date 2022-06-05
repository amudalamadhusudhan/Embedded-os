 #include <semaphore.h> 
 #include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
sem_t mecount;
int count =0;
void *incThread(void *arg)
{
while(1)
{
sem_wait(&mecount);
count++;
printf("Inc Thread : %d\n",count);
sem_post(&mecount);
}
}
void *decThread(void *arg)
{
    sem_wait(&mecount);
while(1)
{
count--;
printf("dec Thread : %d\n",count);
sem_post(&mecount);
}
}

int main(int argc,char const *argv[])
{
sem_init(&mecount,0,1);
pthread_t inc,dec;
pthread_create(&inc,NULL,incThread,NULL);
pthread_create(&dec,NULL,decThread,NULL);
pthread_join(inc,NULL);
pthread_join(dec,NULL);
sem_destroy(&mecount);

return 0;
}