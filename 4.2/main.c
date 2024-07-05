#include <stdio.h>
#include <stdbool.h>

#define MAXSIZE 110
#define INF 10000

int main () {
    int x = 0;                   //*首先是各个变量的初始化*//
int dist[MAXSIZE][MAXSIZE] = {};

bool isvisited[MAXSIZE] = {};
int len[MAXSIZE] = {};

int stack[MAXSIZE] = {};
int top = -1;
	scanf("%d", &x);             //*通过输入函数获取顶点数量x，然后通过循环依次输入图的邻接矩阵dist。输入完成后，初始化图的邻接矩阵。*//
	for (int i = 0; i < x; ++i)
		for (int j = 0; j < x; ++j)
			scanf("%d", &dist[i][j]);

	for (int i = 0; i < x; ++i) len[i] = INF;//*初始化len数组为INF，表示初时到各顶点的距离为无穷大*//
	isvisited[0] = true; len[0] = 0;   //*将起点0标记为已访问，并更新与起点相邻的顶点到起点的距离*//
	for (int i = 0; i < x; ++i)
		if (dist[0][i] != INF) len[i] = dist[0][i];

	for (int i = 0; i < x - 1; ++i) {//*循环更新未访问顶点的最短距离，直到所有顶点都被访问*//
		int min = INF, next;
		for (int j = 0; j < x; ++j)
			if (!isvisited[j] && len[j] < min)
				min = len[j], next = j;
		isvisited[next] = true;

		for (int j = 0; j < x; ++j)
			if (!isvisited[j] && dist[next][j] != INF) {
				int tmp = len[next] + dist[next][j];
				if(len[j]>=tmp)len[j]=tmp;
			}

	}

	int a, b;
	scanf("%d %d", &a, &b);//*获取起点a和终点b*//
	stack[++top] = b;//*利用堆栈存储路径上的节点，将终点b入栈*//
	while (b != a)//*通过循环找到路径上的节点，直到起点a，将路径节点入栈*//
		for (int i = 0; i < x; ++i)
			if (dist[i][b] != INF && len[i] < len[b] &&
			len[i] + dist[i][b] == len[b])
				stack[++top] = b = i;

	while(top > -1) printf("%d\n", stack[top--]);
	return 0;
}
