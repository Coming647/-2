#include <stdio.h>
#include <math.h>

int main()
{
    int n,m,i=0,j=0;
    scanf("%d %d",&n,&m);
    //*����������������У�����2����������i��j�����������*//
    int *row,*col,*num;
    row=(int *)malloc((n+1)*sizeof(int));
    col=(int *)malloc((m+1)*sizeof(int));
    num=(int *)malloc((m*n)*sizeof(int));
    //*���Ŷ�����Ԫ�飬�ֱ��ʾ�����з���ֵ���У��У���ֵ*//
    while(1)
    {
        scanf("%d %d %d",&row[i],&col[i],&num[i]);
        if(num[i]==0)break;
        i++;
    }
    //*Ȼ��������Ԫ���и���Ԫ�أ�Ӧʵ��Ҫ�󣬽���0 0 0����Ϊ������������Ϊ��Ԫ������ֵ��Ϊ0�����Խ��������ֵΪ0��Ϊ��������*//
    while(j<i)
    {
        printf("%d %d %d\n",col[j],row[j],num[j]);
        j++;
    }
    //*Ȼ��ֱ���Ԫ���и���Ԫ�ذ�ת�þ������*//
    return 0;
}
