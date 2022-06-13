#include <sys/types.h>
#include <sys/socket.h>
#include <linux/types.h>
#include <stdio.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int sfd, cfd;
struct sockaddr_in saddr;
// struct sockaddr_in caddr;
int len;
char buf[1024];

int main(int argc, char const *argv[])
{
    cfd = socket(AF_INET, SOCK_STREAM, 0);
    saddr.sin_family = AF_INET;
    saddr.sin_addr.s_addr = inet_addr("10.0.2.15");
    saddr.sin_port = htons(5678);

    connect(cfd, (struct sockaddr *)&saddr, sizeof(struct sockaddr_in));
    read(cfd, buf, 1024);
    printf("server send %s\n", buf);
    write(cfd, "hello sudhan\n", 13);

    return 0;
}