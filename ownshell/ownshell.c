#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#define size 1024
int main(int argc, char const *argv[])
{
    pid_t id;
    int eq;
    char cmd[size];
    printf("madhusudhan@shell$:");
    id = fork();
    if (id == 0)
    {
        scanf("%s", cmd);
        eq = strcmp("ls", cmd);
        if (eq == 0)
        {
            execl("/usr/bin/ls", "/usr/bin/ls", NULL);
        }
        else
            printf("command not found\n");
        exit(EXIT_FAILURE);
    }
    else
        wait(NULL);
    scanf("%s", cmd);
    eq = strcmp("pwd", cmd);
    if (eq == 0)
    {
        execl("/usr/bin/pwd", "/usr/bin/pwd", NULL);
    }
    else
        printf("command not found\n");
    exit(EXIT_FAILURE);

    return 0;
}