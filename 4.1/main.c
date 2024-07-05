#include <stdio.h>
#include <stdbool.h>

#define MAXSIZE 106
#define INF 10000  //*��ʾ2����ޱ�*//


int main ()
{
    int x = 0;
    int dist[MAXSIZE][MAXSIZE] = {};

    bool isvisited[MAXSIZE] = {};
    int len[MAXSIZE] = {};
	scanf("%d", &x);//*���븳Ȩͼ���ڽӾ���*//
	for (int i = 0; i < x; ++i)
		for (int j = 0; j < x; ++j)
			scanf("%d", &dist[i][j]);

	for (int i = 0; i < x; ++i) len[i] = INF;//*���㲢�洢2���֮����̾��벢�ڴ˹������жϽ���Ƿ񱻷���*//
	isvisited[0] = true; len[0] = 0;
	for (int i = 0; i < x; ++i)
		if (dist[0][i] != INF) len[i] = dist[0][i];

	for (int i = 0; i < x - 1; ++i) {
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



	for (int i = 0; i < x; ++i)//*���Ŀ����*//
		printf("%d\n", len[i]);
	return 0;
}
