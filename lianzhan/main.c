#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define maxsize 50

typedef struct snode
{
    int data;
    struct snode *next;

}stack,*tack;


tack creat()
{
    tack s1;
    s1=(tack)malloc(sizeof(stack));
    s1->next=NULL;
    return s1;
}


bool isempty(stack *s)
{
    return(s->next==NULL);
}

void push(stack *s,int x)
{
    stack *p;
    p=(stack *)malloc(sizeof(stack));
    p->data=x;
    p->next=s->next;
    s->next=p;
}

int pop(stack *s)
{
    stack *q;
    q=(stack *)malloc(sizeof(stack));
    int x;
    if(isempty(s))return false;
    else
    {
        q=s->next;
        x=q->data;
        q=q->next;
        s->next=q;
        return x;
    }
}


int main()
{
    tack s;
    s=(stack *)malloc(sizeof(stack));
    s=creat();
    push(s,12330);
    push(s,5655);
    push(s,9999);
    while(!isempty(s))
    {
        printf("%d ",pop(s));
    }
    return 0;
}
