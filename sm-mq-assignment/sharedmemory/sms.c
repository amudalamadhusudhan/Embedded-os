#include <stdio.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/types.h>
#include <unistd.h>
struct process
{
    pid_t pid, ppid;
};

int *count = NULL;
int main(int argc, char const *argv[])
{
    struct process p1 = {getpid(), getppid()};
    struct process *count = &p1;
    int shmfd;
    shmfd = shm_open("/madhusudhanshm", O_CREAT | O_RDWR, S_IWGRP | S_IRUSR | S_IRGRP | S_IWUSR);
    if (shmfd == -1)
    {
        perror("shm_open\n");
        return EXIT_FAILURE;
    }
    ftruncate(shmfd, sizeof(int));
    count = (struct process *)mmap(NULL, sizeof(struct process), PROT_READ | PROT_WRITE, MAP_SHARED, shmfd, 0); // shared memory mapped to our adrress space
    printf("process pid:%d\n", count->pid);
    printf("process parent id ppid:%d\n", count->ppid);
    return 0;
}