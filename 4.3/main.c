#include <stdio.h>
#include <stdbool.h>
#define MAXSIZE 110

int main () {
    int x = 0;
    int dist[MAXSIZE][MAXSIZE] = {};
	scanf("%d", &x);
	for (int i = 0; i < x; ++i)//*初始化图的邻接矩阵，读取顶点数量和邻接矩阵中各边的权值*//
    {
        for (int j = 0; j < x; ++j)
        {
            scanf("%d", &dist[i][j]);
        }
    }
	for (int n = 0; n < x; ++n)//*利用三重循环遍历所有顶点，根据Floyd算法的原理更新每对顶点之间的最短路径长度。*//
		{
		    for (int i = 0; i < x; ++i)
			{
			    for (int j = 0; j < x; ++j)
				{
				    if (dist[i][n] + dist[n][j] < dist[i][j])
					dist[i][j] = dist[i][n] + dist[n][j];
				}
			}
		}
	int n;
	scanf("%d", &n);//*输出每对顶点之间的最短路径长度*//
	for (int i = 0; i < n; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%d\n", dist[a][b]);
	}
	return 0;
}
