#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_mutex_t mutex_count;
int count = 1;
void *incThread(void *arg)
{
    while (2)
    {
        pthread_mutex_lock(&mutex_count);
        count++;
        printf("inc sleeping\n");
        sleep(10);
        printf("Inc Thread : %d\n", count);
        pthread_mutex_unlock(&mutex_count);
    }
}
void *decThread(void *arg)
{
    int res=0;
    while (2)
    {
        res=pthread_mutex_trylock(&mutex_count);
        printf("result : %d\n",res);
        if(res==0)
        {
        count--;
        printf("dec Thread : %d\n", count);
        pthread_mutex_unlock(&mutex_count);
         }  
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
    return 1;
}