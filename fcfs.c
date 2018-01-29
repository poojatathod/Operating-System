#include<stdio.h>
#include<stdlib.h>


struct processes
{
	int i,pid,at,bt,tat,wt,st,et;

};

int main()
{
struct processes p[3],temp;

FILE *fp;
fp=fopen("input.txt", "r");
int j,i,np,time,cpt;
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

time=0;

for(i=0;i<np;i++)
{
p[i].st=time;
cpt=p[i].bt;
while(cpt>0)
{
time++;
cpt--;
}
p[i].et=time;
}

for(i=0;i<np;i++)
{
p[i].wt=p[i].st-p[i].at;
p[i].tat=p[i].et-p[i].at;
}

fclose(fp);
fp=fopen("input.txt","a");


fprintf(fp,"\n\nPID\tArival_Time\tBus_Time\tStart_Time\tEnd_Time\tWaiting_Time\tTurn_Around_T\n");

for(i=0;i<np;i++)
{
fprintf(fp,"%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",p[i].pid,p[i].at,p[i].bt,p[i].st,p[i].et,p[i].wt,p[i].tat);
}
return 0;
}


