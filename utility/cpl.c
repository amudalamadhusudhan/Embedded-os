#include<stdio.h>
#include<stdlib.h>
#define size 1000000

int main(int argc,char const *argv[])
{
    char buf[size];
FILE *fp,*fp1;
fp=fopen(argv[1],"r");
if(fp==NULL)
{
printf("error in open file doesnt consist in directory");
exit(EXIT_FAILURE);
}
fp1=fopen(argv[2],"w+");
while(fscanf(fp,"%s\n",buf)!=EOF)
{
fprintf(fp1,"%s\n",buf);    
}
fclose(fp);
fclose(fp1);
return 0;
}