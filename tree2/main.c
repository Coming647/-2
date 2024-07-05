#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node *left;
	struct node *right;
}Node, *Tree;

Tree create_tree(void)
{
	Tree root;

	int a;
	scanf("%d", &a);
	if (a == 0) {
		root = NULL;
		return;
	}
	else {
		root = (Tree)malloc(sizeof(Node));
		root->data = a;
		root->left = create_tree();
		root->right = create_tree();
	}

	return root;
}

void preorder(Tree root)
{
	if (root != NULL) {
		printf("data is %d\n", root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

void inorder(Tree root)
{
	if (root != NULL) {
		inorder(root->left);
		printf("data is %d\n",root->data);
		inorder(root->right);
	}
}

void postorder(Tree root)
{
	if (root != NULL) {
		postorder(root->left);
		postorder(root->right);
		printf("data is %d\n",root->data);
	}
}

int main(int argc, char **argv)
{
	Tree root;
	root = create_tree();
	printf("preorder:\n");
	preorder(root);
	printf("inorder:\n");
	inorder(root);
	printf("postorder:\n");
	postorder(root);

	return 0;
}
