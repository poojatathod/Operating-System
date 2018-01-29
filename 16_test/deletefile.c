#include<stdio.h>
#include<unistd.h>

int main(int argc,char *argv[])
{
   if(unlink(argv[1])==-1)
        printf("FAILED: File %s not deleted",argv[1]);
    else
        printf("sucess: File %s deleted",argv[1]);
    return 0;
}
