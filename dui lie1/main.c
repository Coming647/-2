#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define maxsize 50
typedef struct qnode
{
    int data[maxsize];
    int front,rear;
}queue,*que;


que creat(int max)
{
    que s1;
    s1=(queue *)malloc(sizeof(queue));
    s1->front=s1->rear=0;
    return s1;
}


bool isfull(queue *s)
{
    return ((s->rear+1)%maxsize==s->front);//*%maxsize的操作是让整个队列是一个环*//
}

bool add(queue *s,int x)
{
    if(isfull(s))
    {
        printf("╤сапрябЗ");
        return false;
    }
    else
    {
        s->rear=(s->rear+1)%maxsize;
        s->data[s->rear]=x;
        return true;
    }
}

bool iskong(queue *s)
{
    return (s->front==s->rear);
}

int del(queue *s)
{
    if(iskong(s))return false;
    else
    {
        s->front=(s->front+1)%maxsize;
        return s->data[s->front];
    }
}



int main()
{
    queue *s;
    s=(queue *)malloc(sizeof(queue));
    s=creat(maxsize);
    add(s,989879);
    add(s,54545);
    add(s,848941);
    add(s,8451654);
    add(s,135454);
    while(!iskong(s))
    {
        printf("%d ",del(s));
    }
    return 0;
}
