#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>

typedef struct {
	int ch, weight;
	int parent, rleft, right;
} HFMtree;
//*构建哈夫曼树*//
typedef struct {
	bool bit [128];
	char ch, begin;
} HFMcode;
//*哈夫曼编码存储*//
int main () {
	int n;
	scanf("%d", &n);
    HFMtree *ht1 = (HFMtree*) calloc(2 * n, sizeof(HFMtree));
    //*创建一个大小为2*n的HTree结构体数组，即哈夫曼树的存储结构。*//
	int tmp = 1;
	while(tmp <= n) {
		char ch = getchar();
		if (ch != ' ' && ch != '\n') ht1[tmp++].ch = ch;
	}
	for (int i = 1; i <= n; ++i) scanf("%d", &ht1[i].weight);
    //*通过循环从标准输入中获取字符和权重，构建初始的哈夫曼树结构*//
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
	//*循环构建哈夫曼树的非叶子节点，直到所有节点都被合并为一个根节点*//
	HFMtree *ht =ht1;
    HFMcode *hc1 = (HFMcode*) calloc(n + 1, sizeof(HFMcode));
    //*创建一个大小为n+1的HCode结构体数组，用于存储字符的哈夫曼编码*//
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
	//*遍历哈夫曼树数组，根据每个叶子节点的路径生成对应的哈夫曼编码*//
	HFMcode *hc =hc1;
	char text[1001] = "";
	scanf("%s", text);
	//*创建一个字符串数组text用于存储输入的文本*//
	for (int i = 0; i < strlen(text); ++i) {
		for (int j = 1; j <= n; ++j) {
			if (text[i] == hc[j].ch) {
				for (int k = hc[j].begin; k <= n; ++k) {
					printf("%d", hc[j].bit[k]);
				}
			}
		}
	}
	//*遍历文本中的每个字符，根据字符在哈夫曼编码数组中的位置输出对应的哈夫曼编码。*//
	printf("\n%s\n", text);
	return 0;
}
