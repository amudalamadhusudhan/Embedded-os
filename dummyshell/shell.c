#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main(int argc, char const *argv[])
{
    pid_t id;

    id = fork();
    if (id == 0)
    {
        printf("iam the child procrss\n");
        execl("./threaddemo", "./threaddemo", NULL);
    }
    else
        printf("iam the parent process\n");
    wait(NULL);
    return 0;
}