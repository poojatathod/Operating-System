#include<stdio.h>
#include<stdlib.h>
#include "queue.h"

struct processes
{
	int i,pid,at,bt,tat,wt,st,et;

};

int main()
{
queue rq;
rq.top=NULL;
struct processes p[3],temp;

FILE *fp;
fp=fopen("rrinput.txt", "r");
int j,i,np,time;
fscanf(fp,"%d",&np);

for(i=0;i<np;i++)
{
	fscanf(fp,"%d %d %d",&p[i].pid,&p[i].at,&p[i].bt);
}

printf("\n");

for(j=0;j<np;j++)
{
for(i=0;i<(np-1);i++)
{
if(p[i].at>p[i+1].at)
{
temp=p[i];
p[i]=p[i+1];
p[i+1]=temp;	
}
}
}

for(i=0;i<np;i++)
{
add(&rq,i);
}

time=0;
int index;
while(!isempty(&rq))
{
index=rq.top->data;
printf(" %d | P %d |",time,p[index].pid);
p[index].bt--;
time++;
printf(" %d ",time);
delete(&rq);
if(p[index].bt!=0)
{
add(&rq,index);
}
}

/*fclose(fp);
fp=fopen("rrinput.txt","a");


fprintf(fp,"\n\nPID\tArival_Time\tBus_Time\tStart_Time\tEnd_Time\tWaiting_Time\tTurn_Around_T\n");

for(i=0;i<np;i++)
{
fprintf(fp,"%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",p[i].pid,p[i].at,p[i].bt,p[i].st,p[i].et,p[i].wt,p[i].tat);
}*/

return 0;
}


