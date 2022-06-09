#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
 
int a,b;
sem_t sem_i2p,sem_p2i;
void *inputThread(void *data)
 {
while(1)
{
    sem_wait(&sem_p2i);
scanf("%d",&a);
scanf("%d",&b);
sem_post(&sem_i2p);
sem_post(&sem_i2p);
}
 }
void *processingThread(void *data)
{
    int sum;
while(1)
{
    sem_wait(&sem_i2p);
    sem_wait(&sem_i2p);
sum=a+b;
printf("sum :%d\n",sum);
sem_post(&sem_p2i);
}
}



int main(int argc ,char const *argv[])
{

pthread_t inputTid,procssingTid;
sem_init(&sem_p2i,0,1);
sem_init(&sem_i2p,0,1);
pthread_create(&inputTid,NULL,inputThread,NULL);
pthread_create(&procssingTid,NULL,processingThread,NULL);
pthread_join(inputTid,NULL);
pthread_join(procssingTid,NULL);


return 0;


}