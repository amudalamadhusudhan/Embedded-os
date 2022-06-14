#include <stdio.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <fcntl.h>    /* For O_* constants */
#include <sys/stat.h> /* For mode constants */
#include <semaphore.h>
#include <sys/mman.h>
#include <unistd.h>
#include <sys/types.h>
int *count = NULL;
int main(int argc, char const *argv[])
{
    int shmfd;
    sem_t *countsem;
    countsem = sem_open("/madhusudhansem", O_CREAT | O_RDWR, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP, 1);

    shmfd = shm_open("/madhusudhanshm", O_CREAT | O_RDWR, S_IWGRP | S_IRUSR | S_IRGRP | S_IWUSR);
    if (shmfd == -1)
    {
        perror("shm_open\n");
        return EXIT_FAILURE;
    }
    ftruncate(shmfd, sizeof(int));
    count = (int *)mmap(NULL, sizeof(int), PROT_READ | PROT_WRITE, MAP_SHARED, shmfd, 0); // shared memory mapped to our adrress space
    while (1)
    {
        sem_wait(countsem);
        *count = *count + 1;
        // sleep(1);
        sem_post(countsem);
    }

    return 0;
}