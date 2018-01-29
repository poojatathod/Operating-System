#include "sll.h"
#include<stdio.h>
#include<stdlib.h>
#define maxsize 50

typedef struct stack
{
struct node *top;
}stack;

int size(stack *s)
{
return length(s->top);
}

int isempty(stack *s)
{
if(s->top!=NULL)
return 0;
else 
return 1;
}

int isfull(stack *s)
{
if(size(s)<maxsize)
return 0;
else 
return 1;
}


void push(stack *s,int val)
{

//if(!isfull(s))
{
s->top=insertfront(s->top,val);
}
//else
//{ 
//printf("your stack is full");
//}
}


int pop(stack *s)
{
int ele;
if(!isempty(s))
{
ele=s->top->data;
s->top=deletefront(s->top);
return ele;
}
else
{
printf("your stack is empty");
return -1;
}
}








