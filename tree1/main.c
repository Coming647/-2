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
	//�����������������
	int e;
	scanf("%d",&e);
	if(e==-1)
        *t=NULL;
	else
	{
		*t=(BiTree)malloc(sizeof(BiTNode));
		(*t)->data=e;
		printf("������%d�����ӽڵ��ֵ��",e);
		createBiTree(&(*t)->lchild);
		printf("������%d�����ӽڵ��ֵ��",e);
		createBiTree(&(*t)->rchild);
	}
}
void PreOrderTraverse(BiTree t)
{
	//�ݹ��������
	if(t!=NULL)
	{
		printf("%d",t->data);
		PreOrderTraverse(t->lchild);
		PreOrderTraverse(t->rchild);
	}
}
void InOrderTraverse(BiTree t)
{
	//�ݹ��������
	if(t!=NULL)
	{
		InOrderTraverse(t->lchild);
		printf("%d",t->data);
		InOrderTraverse(t->rchild);
	}
}
void PostOrderTraverse(BiTree t)
{
	//�ݹ�������
	if(t!=NULL)
	{
		PostOrderTraverse(t->lchild);
		PostOrderTraverse(t->rchild);
		printf("%d",t->data);
	}
}
void aPreOrderTraverse(BiTree t)
{
	//�ǵݹ��������
	BiTree stack[MAXSIZE];
	int top=0;
	if(t==NULL)
		return;
	BiTree p=t;
	while(!(p==NULL&&top==0))
	{
		while(p)
		{
			printf("%d",p->data);//�ȷ��ʸ����
			stack[top]=p;//��p��ջ
			top++;
			p=p->lchild;//pָ������
		}
		if(top<=0)return;
		else
		{
			top--;
			p=stack[top];
			p=p->rchild;//pָ���Һ���
		}
	}
}
int main()
{
	BiTree t;
	printf("��������ڵ��ֵ��");
	t=createBiTree();
	printf("�ݹ��������������Ϊ��");
	PreOrderTraverse(t);
	printf("\n");
	printf("�ݹ��������������Ϊ��");
	InOrderTraverse(t);
	printf("\n");
	printf("�ݹ�������������Ϊ��");
	PostOrderTraverse(t);
	printf("\n");
	printf("�ǵݹ��������������Ϊ��");
	aPreOrderTraverse(t);
	printf("\n");
}
