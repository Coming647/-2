#include <stdio.h>
#include <stdbool.h>
#define MAXSIZE 110

    int path[MAXSIZE][MAXSIZE] = {};//*写在主函数之外，保证调用函数也可以使用*//
    int stack[MAXSIZE] = {};
    int top = -1;

void find(int a, int b) {   //*递归函数，用于在最短路径计算后根据路径矩阵path[][]来回溯找出从顶点a到顶点b的具体路径。将路径上的顶点依次存入栈中。*//
	stack[++top] = b;
	if (path[a][b] == -1) {
		stack[++top] = a;
		return;
	}
	find(a, path[a][b]);
}

int main () {
    int x = 0;
    int dist[MAXSIZE][MAXSIZE] = {};

	scanf("%d", &x);
	for (int i = 0; i < x; ++i)//*值初始化图的邻接矩阵，首先从标准输入中读取顶点数量x，然后依次读取各顶点之间的边的权值，并将其存储在二维数组dist[][]中。同时，对路径矩阵path[][]进行初始化，将其全部设为-1*//
		{
		    for (int j = 0; j < x; ++j) {
			scanf("%d", &dist[i][j]);
			path[i][j] = -1;
		}
		}


	for (int n = 0; n < x; ++n)//*三重循环逐步更新顶点间的最短路径长度。通过判断经过节点n到达节点j的路径是否比直达路径更短，若是则更新最短路径长度，并记录路径信息到path[][]矩阵中*//
		{
		    for (int i = 0; i < x; ++i)
			{
			    for (int j = 0; j < x; ++j)
				if (dist[i][n] + dist[n][j] < dist[i][j]) {
					dist[i][j] = dist[i][n] + dist[n][j];
					path[i][j] = n;
				}
			}
		}


	int n;
	scanf("%d", &n);//*从标准输入中读取需要查询的顶点对数量n，然后依次读取用户输入的顶点对，并调用find()函数找出它们之间的最短路径并输出*//
	for (int i = 0; i < n; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		top = -1;
		find(a, b);
		while (top > -1) printf("%d\n", stack[top--]);
	}
	return 0;
}
