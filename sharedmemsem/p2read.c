#include <stdio.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <unistd.h>
#include <semaphore.h>
#include <sys/mman.h>
#include <unistd.h>
#include <sys/types.h>
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
        printf("%d\n", *count);
        sem_post(countsem);
    }
    sem_close(countsem);
    return 0;
}