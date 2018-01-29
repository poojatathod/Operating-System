#include<stdio.h>
#include<stdlib.h>

typedef struct process
{
int psize,bindex;
}process;

typedef struct blocks
{
int flag,bsize;
}block;

int min(int temp[],int size)
{
int i,minimum,index;
minimum=1000000;
index=0;
for(i=0;i<7;i++)
{
if(temp[i]<minimum && temp[i]>0)
{
minimum=temp[i];
index=i;
}
}
return index;
}


int max(block b[])
{

int i,maximum=0;
for(i=0;i<5;i++)
{
if(b[i].bsize>maximum)
{
maximum=b[i].bsize;
}
}
return maximum;
}

void main()
{
int i,j,temp[7],temp1;
block b[7];
process p[6];

p[0].psize=212;
p[1].psize=417;
p[2].psize=112;
p[3].psize=426;
p[4].psize=1;
p[5].psize=2;


b[0].bsize=100;
b[1].bsize=500;
b[2].bsize=200;
b[3].bsize=300;
b[4].bsize=600;
b[5].bsize=700;
b[6].bsize=900;

for(i=0;i<7;i++)
b[i].flag=0;



for(i=0;i<6;i++)
{
for(j=0;j<7;j++)
{
if(b[j].flag!=1)
{
temp[j]=b[j].bsize-p[i].psize;
}
else
{
temp[j]=max(b);
}
}
p[i].bindex=min(temp,7);
b[p[i].bindex].flag=1;
printf("%d\t%d\n",p[i].psize,b[p[i].bindex].bsize);
}

}



/*void main()
{

int temp[]={1,20,30,3,7};
min(temp,5);
}*/



