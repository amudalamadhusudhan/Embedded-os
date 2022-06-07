#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
int count = 0;
pthread_rwlock_t count_rwlock;
void *reader1(void *data)
{
int z;
printf("reader 1 entering critical section\n");
pthread_rwlock_rdlock(&count_rwlock);
printf("reader 1 inside the critical\n");
z=count+10;
printf("value of reader1 count %d",count);
pthread_rwlock_unlock(&count_rwlock);
printf("reade 1 leaving the critical section\n");
}
void *reader2(void *data)
{
    int x;
    printf("reader 2 entering the critical section\n");
    pthread_rwlock_rdlock(&count_rwlock);
    printf("reader 2 inside the critical section\n");
x=count +20;
pthread_rwlock_unlock(&count_rwlock);
printf("value of reader2 count %d",count);
printf("reader 2 leaving the critical section\n");
}
void *writer1(void *data)
{
    printf("wrinter entering to the critical section\n");
pthread_rwlock_wrlock(&count_rwlock);
printf("writer inside the critical section\n");
printf("writing the count");
count++;
pthread_rwlock_unlock(&count_rwlock);
printf("writer leaving the critical section\n");
}

int main( int argc,char const *argv[])
{
pthread_t r1,r2,w1;
pthread_rwlock_init(&count_rwlock,NULL);
pthread_create(&r1,NULL,reader1,NULL);
pthread_create(&r2,NULL,reader2,NULL);
pthread_create(&w1,NULL,writer1,NULL);
pthread_join(r1,NULL);
pthread_join(r2,NULL);
pthread_join(w1,NULL);
pthread_rwlock_destroy(&count_rwlock);
return 0;




    return 0;
}

