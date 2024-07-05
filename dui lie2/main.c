#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    int data;
    struct node *next;
}qnode,*qno;

typedef struct qqueue
{
    qnode *front;//*注意这里的2指针是上面的那种结构体指针*//
    qnode *rear;
}queue,*que;


que creat()
{
    que s1;
    s1=(que)malloc(sizeof(queue));
    s1->front=(qnode *)malloc(sizeof(qnode));
    s1->rear=(qnode *)malloc(sizeof(qnode));
    s1->front->next=NULL;
    s1->rear=s1->front;
    return s1;

}


bool iskong(queue *s)
{
    return (s->front==NULL);
}


int  del(queue *s)
{
    qnode *p;
    p=(qnode *)malloc(sizeof(qnode));
    int x;
    if(iskong(s))return false;
    else
    {
        p=s->front;//*要删除的结点*//
        if(s->front==s->rear)
        {
            s->front=NULL;
            s->rear=NULL;
        }
        else
        {
            s->front=s->front->next;
        }
        x=p->data;
        free(p);
        return x;
    }
}

void add(queue *s,int x)
{
    if(iskong(s))
    {
        qnode *q;
        q=(qnode *)malloc(sizeof(qnode));
        q->data=x;
        s->rear->next=q;
        s->rear=q;
        s->front=s->rear;
    }
    else
    {
    qnode *q;//*这里的q和上面的p都是辅助插入和删除的结点*//
    q=(qnode *)malloc(sizeof(qnode));
    q->data=x;
    s->rear->next=q;
    s->rear=q;
    }

}

int main()
{

    queue *s;
    s=(queue *)malloc(sizeof(queue));//*注意指针类型*//
    s=creat();
    add(s,45465);
    add(s,54154);
    add(s,54648);
    add(s,99874);
    if(s->front!=s->rear)s->front=s->front->next;
    while(!iskong(s))
    {
        printf("%d ",del(s));
    }
    return 0;
}
