#include <sys/types.h>
#include <sys/socket.h>
#include <linux/types.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <stdio.h>

int sfd;
int cfd;
struct sockaddr_in saddr;
struct sockaddr_in caddr;
int len;
char buf[1024];

int main(int argc, char const *argv[])
{
    sfd = socket(AF_INET, SOCK_STREAM, 0);
    saddr.sin_family = AF_INET;
    saddr.sin_addr.s_addr = inet_addr("10.0.2.15");
    saddr.sin_port = htons(5678);
    bind(sfd, (struct sockaddr *)&saddr, sizeof(struct sockaddr_in));
    listen(sfd, 10);

    len = sizeof(struct sockaddr_in);
    cfd = accept(sfd, (struct sockaddr *)&caddr, &len);

    write(cfd, "hello madhu \n", 13);
    read(cfd, buf, 1024);
    printf("client sent %s\n", buf);
    close(sfd);
    close(cfd);
    return 0;
}