#include<stdio.h>
#include"arith.h"

int main(int argv, char const *argc[])
{
int a=10,b=20,result,result2;
printf("arith demo\n");
result=add(a,b);
result2=sub(a,b);
printf("addition Result :%d\n",result);
printf("subraction Result :%d\n",result2);
return 0;
}
