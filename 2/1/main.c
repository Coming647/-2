#include <stdio.h>
#include <math.h>

int main()
{
    int n,m,i=0,j=0;
    scanf("%d %d",&n,&m);
    //*首先输入矩阵行与列，定义2个辅助变量i，j方便下面计算*//
    int *row,*col,*num;
    row=(int *)malloc((n+1)*sizeof(int));
    col=(int *)malloc((m+1)*sizeof(int));
    num=(int *)malloc((m*n)*sizeof(int));
    //*接着定义三元组，分别表示矩阵中非零值的行，列，数值*//
    while(1)
    {
        scanf("%d %d %d",&row[i],&col[i],&num[i]);
        if(num[i]==0)break;
        i++;
    }
    //*然后输入三元组中各项元素，应实验要求，将“0 0 0”作为结束条件，因为三元组中数值不为0，所以将输入的数值为0作为结束条件*//
    while(j<i)
    {
        printf("%d %d %d\n",col[j],row[j],num[j]);
        j++;
    }
    //*然后分别将三元组中各项元素按转置矩阵输出*//
    return 0;
}
