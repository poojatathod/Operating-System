#include<stdio.h>

int main()
{
int i,j,k;
int proc[3],at[3],bt[3],st[3],ct[3],tat[3],wt[3];

for(i=0;i<3;i++)
{
scanf("%d%d%d",&proc[i],&at[i],&bt[i]);
}

/*for(i=0;i<3;i++)
{
printf("\n%d\t%d\t%d\t\n",proc[i],at[i],bt[i]);
}
*/
st[0]=at[0];
ct[0]=bt[0];

for(i=1;i<3;i++)
{
st[i]=ct[i-1];
ct[i]=st[i]+bt[i];
scanf("%d%d",&st[i],ct[i]);
}

for(i=0;i<3;i++)
{
printf("%d\t%d\t%d\t%d\t%d\n",proc[i],at[i],bt[i],st[i],ct[i]);
}
return 0;
}
