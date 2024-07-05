#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 200
typedef int TElemType;
typedef struct BiTNode{
	TElemType data;
	struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;
BiTree createBiTree()
{
	//先序遍历创建二叉树
	int e;
	scanf("%d",&e);
	if(e==-1)
        *t=NULL;
	else
	{
		*t=(BiTree)malloc(sizeof(BiTNode));
		(*t)->data=e;
		printf("请输入%d的左子节点的值：",e);
		createBiTree(&(*t)->lchild);
		printf("请输入%d的右子节点的值：",e);
		createBiTree(&(*t)->rchild);
	}
}
void PreOrderTraverse(BiTree t)
{
	//递归先序遍历
	if(t!=NULL)
	{
		printf("%d",t->data);
		PreOrderTraverse(t->lchild);
		PreOrderTraverse(t->rchild);
	}
}
void InOrderTraverse(BiTree t)
{
	//递归中序遍历
	if(t!=NULL)
	{
		InOrderTraverse(t->lchild);
		printf("%d",t->data);
		InOrderTraverse(t->rchild);
	}
}
void PostOrderTraverse(BiTree t)
{
	//递归后序遍历
	if(t!=NULL)
	{
		PostOrderTraverse(t->lchild);
		PostOrderTraverse(t->rchild);
		printf("%d",t->data);
	}
}
void aPreOrderTraverse(BiTree t)
{
	//非递归先序遍历
	BiTree stack[MAXSIZE];
	int top=0;
	if(t==NULL)
		return;
	BiTree p=t;
	while(!(p==NULL&&top==0))
	{
		while(p)
		{
			printf("%d",p->data);//先访问根结点
			stack[top]=p;//将p入栈
			top++;
			p=p->lchild;//p指向左孩子
		}
		if(top<=0)return;
		else
		{
			top--;
			p=stack[top];
			p=p->rchild;//p指向右孩子
		}
	}
}
int main()
{
	BiTree t;
	printf("请输入根节点的值：");
	t=createBiTree();
	printf("递归先序遍历二叉树为：");
	PreOrderTraverse(t);
	printf("\n");
	printf("递归中序遍历二叉树为：");
	InOrderTraverse(t);
	printf("\n");
	printf("递归后序遍历二叉树为：");
	PostOrderTraverse(t);
	printf("\n");
	printf("非递归先序遍历二叉树为：");
	aPreOrderTraverse(t);
	printf("\n");
}
