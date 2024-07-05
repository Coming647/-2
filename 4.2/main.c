#include <stdio.h>
#include <stdbool.h>

#define MAXSIZE 110
#define INF 10000

int main () {
    int x = 0;                   //*�����Ǹ��������ĳ�ʼ��*//
int dist[MAXSIZE][MAXSIZE] = {};

bool isvisited[MAXSIZE] = {};
int len[MAXSIZE] = {};

int stack[MAXSIZE] = {};
int top = -1;
	scanf("%d", &x);             //*ͨ�����뺯����ȡ��������x��Ȼ��ͨ��ѭ����������ͼ���ڽӾ���dist��������ɺ󣬳�ʼ��ͼ���ڽӾ���*//
	for (int i = 0; i < x; ++i)
		for (int j = 0; j < x; ++j)
			scanf("%d", &dist[i][j]);

	for (int i = 0; i < x; ++i) len[i] = INF;//*��ʼ��len����ΪINF����ʾ��ʱ��������ľ���Ϊ�����*//
	isvisited[0] = true; len[0] = 0;   //*�����0���Ϊ�ѷ��ʣ���������������ڵĶ��㵽���ľ���*//
	for (int i = 0; i < x; ++i)
		if (dist[0][i] != INF) len[i] = dist[0][i];

	for (int i = 0; i < x - 1; ++i) {//*ѭ������δ���ʶ������̾��룬ֱ�����ж��㶼������*//
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
	scanf("%d %d", &a, &b);//*��ȡ���a���յ�b*//
	stack[++top] = b;//*���ö�ջ�洢·���ϵĽڵ㣬���յ�b��ջ*//
	while (b != a)//*ͨ��ѭ���ҵ�·���ϵĽڵ㣬ֱ�����a����·���ڵ���ջ*//
		for (int i = 0; i < x; ++i)
			if (dist[i][b] != INF && len[i] < len[b] &&
			len[i] + dist[i][b] == len[b])
				stack[++top] = b = i;

	while(top > -1) printf("%d\n", stack[top--]);
	return 0;
}
