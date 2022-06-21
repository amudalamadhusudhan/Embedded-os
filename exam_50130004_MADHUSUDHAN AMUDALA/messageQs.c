#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <mqueue.h>
#include <stdlib.h>
#define msg_size 10000
struct mq_attr attr;
mqd_t mqd;
int main(int argc, char const *argv[])
{
    attr.mq_curmsgs = 0;
    attr.mq_maxmsg = 4;
    attr.mq_msgsize = msg_size;
    attr.mq_flags = 0;
    mqd = mq_open( "/usr/include/stdio.h", O_CREAT | O_RDWR, S_IRUSR | S_IWUSR, &attr); // created msg Q
    if (mqd == -1)
    {
        perror("mq_open\n");
        exit(EXIT_FAILURE);
    }
    mq_send(mqd, "/usr/include/stdio.h",msg_size, 0);
    mq_close(mqd);
    return 0;
}