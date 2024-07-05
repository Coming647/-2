#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define maxsize 50

typedef struct snode
{
    int *data;
    int top;
}stack,*tack;

tack creat(int max)
{
    tack s1;
    s1=(tack)malloc(sizeof(stack));
    s1->data=(int *)malloc(max*sizeof(int));
    s1->top=-1;
    return s1;
}


bool isfull(stack *s)
{
    return (s->top==maxsize-1);//*if(s->top==maxsize-1)return true;else return false;*//
}

bool push(stack *s,int x)
{
    if(isfull(s))
    {
        printf("栈已满");
        return false;
    }
    else
    {
        s->data[++(s->top)]=x;
        return true;
    }
}

bool isempty(stack *s)
{
    return(s->top==-1);
}

int pop(stack *s)
{
    if(isempty(s))
    {
        printf("栈已空");
        return false;
    }
    else
    {
        return(s->data[(s->top)--]);//*注意与上面的前置--运算顺序不同*//
    }
}

int main()
{
    tack s;
    s=(tack)malloc(sizeof(stack));
    s=creat(maxsize);
    push(s,4);
    push(s,6);
    push(s,3);
    while(!(isempty(s)))
    {
        printf("%d ",pop(s));
    }
    return 0;
}
