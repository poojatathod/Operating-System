#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
int data;
struct node *next;
}node;

node * create(int val)
{
node *nn;
nn=(node *)malloc(sizeof(node));
nn->data=val;
nn->next=NULL;
return nn;
}

node *insertlast(node *start,int val)
{
node *nn;
if(start==NULL)
{
return create(val );
}
else
{
start->next=insertlast(start->next,val);
return start;
}
}

void display(node *start)
{
if(start!=NULL)
{
printf("%d->",start->data);
display(start->next);
}
}

node *insertfront(node *start,int val)
{
node *temp;
temp=create(val);
temp->next=start;
return temp;
}

node *insertpos(node *start, int val,int p)
{
node *temp,*temp1;
/*
int i;
for(i=1, temp=start;i<(p-1);i++,temp=temp->next);
temp1=create(val);
temp1->next=temp->next;
temp->next=temp1;
*/

if(start==NULL)
{
return create(val);
}
else if(p==2)
{
temp=start->next;
start->next=create(val);
start->next->next=temp;
}
else
{
start->next=insertpos(start,val,p-1);
return start;	
}
}


void deletelast(node *start)
{
node *temp;
if(start->next->next==NULL)
{
temp=start->next;
free(temp);
start->next=NULL;
}
else
{
 deletelast(start->next);
}
}

/*for(temp=start;temp->next->next!=NULL;temp=temp->next);
temp=temp->next=NULL;
free(temp);
return start;*/


node *deletefront(node *start)
{
node *temp;
temp=start;
start=temp->next;
free(temp);
return start;
}

node *deletepos(node *start,int pos)
{
node *temp,*temp1;
int i;
for(i=1,temp=start;i<(pos-1);i++,temp=temp->next);

temp1=temp->next;
temp->next=temp->next->next;
free(temp1);
return start;

}


int length(node *start)
{
if(start!=NULL)
{
return (1+length(start->next));
}
else
{ 
return 0;
}
}

int ispresent(node *start, int p)
{
if(!start)
{
return 0;
}
else if(start->data==p)
{
return 1;
}
else
ispresent(start->next,p);
}
