#include <stdio.h>
#include <stdbool.h>
#define MAXSIZE 110

int main () {
    int x = 0;
    int dist[MAXSIZE][MAXSIZE] = {};
	scanf("%d", &x);
	for (int i = 0; i < x; ++i)//*��ʼ��ͼ���ڽӾ��󣬶�ȡ�����������ڽӾ����и��ߵ�Ȩֵ*//
    {
        for (int j = 0; j < x; ++j)
        {
            scanf("%d", &dist[i][j]);
        }
    }
	for (int n = 0; n < x; ++n)//*��������ѭ���������ж��㣬����Floyd�㷨��ԭ�����ÿ�Զ���֮������·�����ȡ�*//
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
	scanf("%d", &n);//*���ÿ�Զ���֮������·������*//
	for (int i = 0; i < n; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%d\n", dist[a][b]);
	}
	return 0;
}
