#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>

typedef struct {
	int ch, weight;
	int parent, rleft, right;
} HFMtree;
//*������������*//
typedef struct {
	bool bit [128];
	char ch, begin;
} HFMcode;
//*����������洢*//
int main () {
	int n;
	scanf("%d", &n);
    HFMtree *ht1 = (HFMtree*) calloc(2 * n, sizeof(HFMtree));
    //*����һ����СΪ2*n��HTree�ṹ�����飬�����������Ĵ洢�ṹ��*//
	int tmp = 1;
	while(tmp <= n) {
		char ch = getchar();
		if (ch != ' ' && ch != '\n') ht1[tmp++].ch = ch;
	}
	for (int i = 1; i <= n; ++i) scanf("%d", &ht1[i].weight);
    //*ͨ��ѭ���ӱ�׼�����л�ȡ�ַ���Ȩ�أ�������ʼ�Ĺ��������ṹ*//
	int min1, min2, rn, ln;
	for (int i = n + 1; i <= 2 * n - 1; ++i) {
		min1 = min2 = INT_MAX; rn = ln = 0;
		for (int j = 1; j <= i - 1; ++j) {
			if (ht1[j].weight < min1 && !ht1[j].parent)
				min2 = min1, rn = ln, min1 = ht1[j].weight, ln = j;
			else if (ht1[j].weight < min2 && !ht1[j].parent)
				min2 = ht1[j].weight, rn = j;
		}
		ht1[ln].parent = ht1[rn].parent = i;
		ht1[i].rleft = ln, ht1[i].right = rn;
		ht1[i].weight = ht1[ln].weight + ht1[rn].weight;
	}
	//*ѭ���������������ķ�Ҷ�ӽڵ㣬ֱ�����нڵ㶼���ϲ�Ϊһ�����ڵ�*//
	HFMtree *ht =ht1;
    HFMcode *hc1 = (HFMcode*) calloc(n + 1, sizeof(HFMcode));
    //*����һ����СΪn+1��HCode�ṹ�����飬���ڴ洢�ַ��Ĺ���������*//
	for (int i = 1; i <= n; ++i) {
		hc1[i].begin = n; hc1[i].ch = ht[i].ch;
		int cn = i, pn = ht[cn].parent;
		while (pn) {
			if (ht[pn].rleft == cn) hc1[i].bit[hc1[i].begin] = 0;
			else hc1[i].bit[hc1[i].begin] = 1;
			--hc1[i].begin, cn = pn, pn = ht[cn].parent;
		}
		++hc1[i].begin;
	}
	//*���������������飬����ÿ��Ҷ�ӽڵ��·�����ɶ�Ӧ�Ĺ���������*//
	HFMcode *hc =hc1;
	char text[1001] = "";
	scanf("%s", text);
	//*����һ���ַ�������text���ڴ洢������ı�*//
	for (int i = 0; i < strlen(text); ++i) {
		for (int j = 1; j <= n; ++j) {
			if (text[i] == hc[j].ch) {
				for (int k = hc[j].begin; k <= n; ++k) {
					printf("%d", hc[j].bit[k]);
				}
			}
		}
	}
	//*�����ı��е�ÿ���ַ��������ַ��ڹ��������������е�λ�������Ӧ�Ĺ��������롣*//
	printf("\n%s\n", text);
	return 0;
}
