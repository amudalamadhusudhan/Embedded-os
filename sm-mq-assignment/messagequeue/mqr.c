#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <mqueue.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

#define msg_size 128
struct mq_attr attr;
mqd_t mqd;
struct process
{
    pid_t pid, ppid;
};
int priority;
int main(int argc, char const *argv[])
{
    attr.mq_curmsgs = 0;
    attr.mq_maxmsg = 4;
    attr.mq_msgsize = msg_size;
    attr.mq_flags = 0;
    struct process p1 = {getpid(), getppid()};
    struct process *count = &p1;
    mqd = mq_open("/madhusudhanmq", O_CREAT | O_RDWR, S_IRUSR | S_IWUSR, &attr); // created msg Q
    if (mqd == -1)
    {
        perror("mq_open\n");
        exit(EXIT_FAILURE);
    }
    mq_receive(mqd, count, msg_size, &priority);
    printf("process pid:%d\n", p1.pid);
    printf("process parent id ppid:%d\n", p1.ppid);
    mq_close(mqd);
    return 0;
}