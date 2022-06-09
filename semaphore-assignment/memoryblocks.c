// memory block manger u
#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
 #define size 10000
int a,b;
sem_t memory,memory1;
int srm=3;

void *Thread1(void *data)
 {
while(1)
{
sem_wait(&memory);
printf("get block of memory1\n");
char m1[size]={"thread1 inside block of memory1\n"};
printf("%s\n",m1);
srm--;
//sem_Post(&memory1);
//printf("realse the block of memory1");
}
 }
void *Thread2(void *data)
{
while(1)
{
    sem_wait(&memory);
printf("get block of memory2\n");
char m2[size]={"thread2 inside block of memory2\n"};
printf("%s\n",m2);
srm--;
//sem_Post(&memory1);
//printf("realse the block of memory2");
}
}
void *Thread3(void *data)
{
   sem_wait(&memory);
printf("get block of memory3\n");
char m3[size]={"thread3 inside block of memory3\n"};
printf("%s\n",m3);
srm--;
sem_post(&memory1);
printf("realse the block of memory3\n");
srm++;
}
void *Thread4(void *data)
{
if(srm<0)
{
printf("wait untill the thread3 realse block memory3\n");
}
else
{
sem_wait(&memory1);
printf("thread4 get block of memory3\n");
char m3[size]={"thread4 inside thr block of memory3\n"};
printf("%s\n",m3);
srm--;
sem_post(&memory);
printf("thread 4 realse the block of memory3\n");
}
}


int main(int argc ,char const *argv[])
{

pthread_t m1Tid,m2Tid,m3Tid,m4Tid;
sem_init(&memory,0,3);
sem_init(&memory1,0,0);
//sem_init(&sem_i2p,0,0);
pthread_create(&m1Tid,NULL,Thread1,NULL);
pthread_create(&m2Tid,NULL,Thread2,NULL);
pthread_create(&m3Tid,NULL,Thread3,NULL);
pthread_create(&m4Tid,NULL,Thread4,NULL);
pthread_join(m1Tid,NULL);
pthread_join(m2Tid,NULL);
pthread_join(m3Tid,NULL);
pthread_join(m4Tid,NULL);
sem_destroy(&memory);


return 0;


}