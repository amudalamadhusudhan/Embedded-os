#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_mutex_t mutex_count;
int count = 0;
void *incThread(void *arg)
{
    while (1)
    {
        printf("Inc Locking 1st time\n");
        pthread_mutex_lock(&mutex_count);
        printf("Inc Locking 2nd time\n");
        pthread_mutex_lock(&mutex_count);
        printf("Inc changing the count \n");
        count++;
        printf("Inc Thread : %d\n", count);
        pthread_mutex_unlock(&mutex_count);
        printf("Inc unLocking 1st time\n");
        pthread_mutex_unlock(&mutex_count);
        printf("Inc unLocking 2nd time\n");
    }
}
void *decThread(void *arg)
{
    while (1)
    {
        pthread_mutex_lock(&mutex_count);
        count--;
        printf("dec Thread : %d\n", count);
        pthread_mutex_unlock(&mutex_count);
    }
}

int main(int argc, char const *argv[])
{

    pthread_t inc, dec;
    pthread_mutex_init(&mutex_count,NULL);
    pthread_create(&inc, NULL, incThread, NULL);
    pthread_create(&dec, NULL, decThread, NULL);
   
    
    pthread_join(inc, NULL);
    pthread_join(dec, NULL);
    pthread_mutex_destroy(&mutex_count);
    return 0;
}