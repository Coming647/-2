#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>




typedef struct bintree
{
    int data;
    struct bintree *lchild;
    struct bintree *rchild;
}node,*tree;

typedef struct snode
{
    tree data;
    struct snode *next;

}stack;

typedef struct node
{
    tree data;
    struct node *next;
}qnode;

typedef struct qqueue
{
    qnode *front;//*注意这里的2指针是上面的那种结构体指针*//
    qnode *rear;
}queue;


bool isempty(stack *s)
{
    return(s->next==NULL);
}

void push(stack *s,tree x)
{
    stack *p;
    p=(stack *)malloc(sizeof(stack));
    p->data=x;
    p->next=s->next;
    s->next=p;
}

tree pop(stack *s)
{
    stack *q;
    q=(stack *)malloc(sizeof(stack));
    tree x;
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

bool iskong(queue *q)
{
    return (q->front==NULL);
}


tree  del(queue *q)
{
    qnode *p;
    p=(qnode *)malloc(sizeof(qnode));
    tree x;
    if(iskong(q))return false;
    else
    {
        p=q->front;//*要删除的结点*//
        if(q->front==q->rear)
        {
            q->front=NULL;
            q->rear=NULL;
        }
        else
        {
            q->front=q->front->next;
        }
        x=p->data;
        return x;
    }
}

void add(queue *q,tree x)
{
    if(iskong(q))
    {
        qnode *Q;
        Q=(qnode *)malloc(sizeof(qnode));
        Q->data=x;
        q->rear->next=Q;
        q->rear=Q;
        q->front=q->rear;
    }
    else
    {
    qnode *Q;//*这里的q和上面的p都是辅助插入和删除的结点*//
    Q=(qnode *)malloc(sizeof(qnode));
    Q->data=x;
    q->rear->next=Q;
    q->rear=Q;
    }

}







//*先序创建二叉树*//
tree  creattree()
{
    tree t;
    int e;                   //*在下面创建二叉树的过程中，若遇到不想构建的结点就输入-1使其为空*//
    scanf("%d",&e);
    if(e==-1)
    {
        t=NULL;
        return false;
    }
    else
    {
        t=(tree )malloc(sizeof(node));
        t->data=e;
        printf("%d的左子结点为",e);
        t->lchild=creattree();//*左孩子结点的值*//
        printf("%d的右子结点为",e);
        t->rchild=creattree();//*右孩子结点的值*//
    }
    return t;
}

void preorder(tree t)
{
    if(t!=NULL)
    {
        printf("%d ",t->data);
        preorder(t->lchild);
        preorder(t->rchild);
    }
}
//*中序非循环*//
void noxunhuan(tree t1,stack *s)
{
    while(t1!=NULL||!isempty(s))
    {
        while(t1!=NULL)
        {
            push(s,t1);
            t1=t1->lchild;
        }
        if(!isempty(s))
        {
            t1=pop(s);
            printf("%d ",t1->data);
            t1=t1->rchild;
        }
    }
}


void cengci(tree t,queue *q)
{
    tree T;
    if(t==NULL)return ;
    add(q,t);
    while(!iskong(q))
    {
        T=del(q);
        printf("%d ",T->data);
        if(T->lchild!=NULL)add(q,T->lchild);
        if(T->rchild!=NULL)add(q,T->rchild);
    }
}

int main()
{
    stack *s;
    s=(stack *)malloc(sizeof(stack));
    s->next=NULL;

    queue *q;
    q=(queue *)malloc(sizeof(queue));//*注意指针类型*//
    q->front=(qnode *)malloc(sizeof(qnode));
    q->rear=(qnode *)malloc(sizeof(qnode));
    q->front->next=NULL;
    q->rear=q->front;


    tree t=creattree();
    tree t1=t;
    preorder(t);
    printf("\n");
    noxunhuan(t1,s);
    printf("\n");


    add(q,t);
    printf("%d",del(q)->data);
    return 0;
}
