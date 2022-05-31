#include<stdio.h>
#include"arith.h"

int main()

{
int output,out2,out3,out4;
output =add(100,30);
out2=sub(100,20);
out3=mul(10,30);
out4=div(100,5);
printf("output addition:%d\n",output);
printf("output subraction:%d\n",out2);
printf("output multiplication:%d\n",out3);
printf("output divisin:%d\n",out4);
return 0;
 


}
