#include<stdio.h>
int add(int a,int b);
int main(int argv, char const *argc[])
{
int a=10,b=20,result;
printf("arith demo\n");
result=add(a,b);
printf("addition Result :%d\n",result);

return 0;
}