#include <stdio.h>
#include <stdbool.h>
#define MAXSIZE 110

    int path[MAXSIZE][MAXSIZE] = {};//*д��������֮�⣬��֤���ú���Ҳ����ʹ��*//
    int stack[MAXSIZE] = {};
    int top = -1;

void find(int a, int b) {   //*�ݹ麯�������������·����������·������path[][]�������ҳ��Ӷ���a������b�ľ���·������·���ϵĶ������δ���ջ�С�*//
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
	for (int i = 0; i < x; ++i)//*ֵ��ʼ��ͼ���ڽӾ������ȴӱ�׼�����ж�ȡ��������x��Ȼ�����ζ�ȡ������֮��ıߵ�Ȩֵ��������洢�ڶ�ά����dist[][]�С�ͬʱ����·������path[][]���г�ʼ��������ȫ����Ϊ-1*//
		{
		    for (int j = 0; j < x; ++j) {
			scanf("%d", &dist[i][j]);
			path[i][j] = -1;
		}
		}


	for (int n = 0; n < x; ++n)//*����ѭ���𲽸��¶��������·�����ȡ�ͨ���жϾ����ڵ�n����ڵ�j��·���Ƿ��ֱ��·�����̣�������������·�����ȣ�����¼·����Ϣ��path[][]������*//
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
	scanf("%d", &n);//*�ӱ�׼�����ж�ȡ��Ҫ��ѯ�Ķ��������n��Ȼ�����ζ�ȡ�û�����Ķ���ԣ�������find()�����ҳ�����֮������·�������*//
	for (int i = 0; i < n; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		top = -1;
		find(a, b);
		while (top > -1) printf("%d\n", stack[top--]);
	}
	return 0;
}
