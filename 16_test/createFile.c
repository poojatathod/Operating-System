#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{

 if(creat(argv[1],700)==-1)
     printf("Failed: Your File %s is not created\n",argv[1]);
 else
     printf("Success: File %s created\n",argv[1]);
return 0;

}
