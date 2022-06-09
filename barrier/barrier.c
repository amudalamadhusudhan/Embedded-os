#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
void *serial_thread(void *data)
{

    printf("serial thread init started\n");
    sleep(7); // serial port takes 7 s so we are assiging  in real world no use sleep
    printf("serial thread init finished\n");
    printf("serial thread main functonality\n");
}

void *ether_thread(void *data)
{
    printf("ethter thread init started\n");

    sleep(10); // emulating the eather thread initilaizaton in real world no use sleep

    printf("ether thread init finished\n");
    printf("ether thread main functonality\n");
}
void *lcd_thread(void *data)
{
    printf("lcd thread init started\n");
    sleep(2); // emulating the eather thread initilaizaton in real world no use sleep
    printf("lcd thread init finished\n");
    printf("lcd thread main functonality\n");
}
int main(int argc, char const *argv[])
{

    pthread_t serial_thread_id, ether_thread_id, lcd_thread_id;
    pthread_create(&serial_thread_id, NULL, serial_thread, NULL);
    pthread_create(&ether_thread_id, NULL, ether_thread, NULL);
    pthread_create(&lcd_thread_id, NULL, lcd_thread, NULL);
    pthread_join(serial_thread_id, NULL);
    pthread_join(ether_thread_id, NULL);
    pthread_join(lcd_thread_id, NULL);

    return 0;
}