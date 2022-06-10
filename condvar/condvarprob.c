#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
int event = 0;
pthread_mutex_t event_mutex;
void *waiting_thread(void *data)
{
    printf("waiting thread grabing the mutex\n");
    pthread_mutex_lock(&event_mutex);
    printf("waiting thread got the mutex\n");
    while (event != 1)
    {
    }
    printf("waiting thread event is 1 so im done \n");
    // actaull code to do
    pthread_mutex_unlock(&event_mutex);
    printf("waiting thread releasing the mutex\n");
}
void *fire_event_thread(void *data) // if waiting threas exutes it goes dead lock
{
    printf("fire thread grabing the mutex\n");
    pthread_mutex_lock(&event_mutex);
    printf("fire thread got the mutex\n");
    event = 1;
    printf("fire thread event is 1 so im done \n");
    // actuall code to do
    pthread_mutex_unlock(&event_mutex);
    printf("fire thread releasing the mutex\n");
}

int main(int argc, char const *argv[])
{
    pthread_t waiting_thread_id, fire_event_thread_id;
    pthread_mutex_init(&event_mutex, NULL);
    pthread_create(&fire_event_thread_id, NULL, fire_event_thread, NULL);
    pthread_create(&waiting_thread_id, NULL, waiting_thread, NULL);
    pthread_join(waiting_thread_id, NULL);
    pthread_join(fire_event_thread_id, NULL);
    pthread_mutex_destroy(&event_mutex);
    return 0;
}