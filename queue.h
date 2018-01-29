#include"stack.h"


typedef stack queue;

void add(queue *q,int val)
{
//if(!isfull(q))
//{
q->top=insertlast(q->top,val);
//}
//else
//{
//printf("Your queue is full");
//}
}



int delete(queue *q)
{
return pop(q);
}


