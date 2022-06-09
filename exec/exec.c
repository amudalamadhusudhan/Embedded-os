#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main(int argv, char const *argc[])
{

    printf("before exec\n");
    execl("/usr/bin/ls", "/usr/bin/ls", NULL);
    printf("after exec\n");

    return 0;
}