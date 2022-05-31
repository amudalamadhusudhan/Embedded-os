#include<stdio.h>
#include"arith.h"

int main(int argv, char const *argc[])
{
int a=20,b=10,result,result2,r3,r4;
printf("arith demo\n");
result=add(a,b);
result2=sub(a,b);
r3=mul(a,b);
r4=div(a,b);
printf("addition Result :%d\n",result);
printf("subraction Result :%d\n",result2);
printf("multiplication Result :%d\n",r3);
printf("division Result :%d\n",r4);
return 0;
}
