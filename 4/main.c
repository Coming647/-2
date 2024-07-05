#include <stdio.h>
#include <stdlib.h>

struct Node {
    int row;
    int col;
    int data;
    struct Node* next;
};


void change(struct Node *objective)
{
    struct Node* p = (struct Node*)malloc(sizeof(struct Node));
    p=objective;
    struct Node* q = (struct Node*)malloc(sizeof(struct Node));
    p=p->next;
    q=objective;
    while(p->next!=NULL)
    {
        if(p->row>p->next->row||(p->row==p->next->row&&p->col>p->next->col))
        {
            q->next=p->next;
            p->next=p->next->next;
            q->next->next=p;
            q=q->next;
        }
        else
        {
            p=p->next;
            q=q->next;
        }
    }
}

int main() {
    int m, n;
    scanf("%d %d", &m, &n);

    struct Node* A = NULL;
    struct Node* B = NULL;
    //*输入好题目参数后就直接创建a，b链表*//
    while (1) {
        int row, col, data;
        scanf("%d %d %d", &row, &col, &data);
        if (row == 0 && col == 0 && data == 0) {
            break;
        }

        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->row = row;
        newNode->col = col;
        newNode->data = data;
        newNode->next = A;
        A = newNode;
    }

    // Read the second matrix
    scanf("%d %d", &m, &n);

    while (1) {
        int row, col, data;
        scanf("%d %d %d", &row, &col, &data);
        if (row == 0 && col == 0 && data == 0) {
            break;
        }

        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->row = row;
        newNode->col = col;
        newNode->data = data;
        newNode->next = B;
        B = newNode;
    }

    //*创建完a，b链表后直接创建目标链表objective*//
    struct Node* objective=(struct Node*)malloc(sizeof(struct Node));
    objective->next=NULL;
    struct Node* current = (struct Node*)malloc(sizeof(struct Node));
    current=objective;
    //*由于矩阵乘法中存在先相乘再相加的步骤，故在这里分开计算，先算出所有可能存在相乘情况*//
    struct Node* currentA = A;
    while (currentA != NULL) {
        struct Node* currentB = B;
        while (currentB != NULL) {
            if (currentA->col == currentB->row) {
                struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
                newNode->row = currentA->row;
                newNode->col = currentB->col;
                newNode->data = currentA->data * currentB->data;
                if(objective->next==NULL)
                {
                    objective->next=newNode;
                    current=newNode;
                }
                else
                {
                    current->next=newNode;
                    current=newNode;
                }
            }
            currentB = currentB->next;
        }
        currentA = currentA->next;
    }
    current->next=NULL;
    current=objective->next;
    //*然后再算相加的情况，注意要将需要加的元素相加后要删除一些同行同列的元素*//
    while (current != NULL) {
        struct Node* p = current->next;
        struct Node* q = current;
        while (p != NULL) {
            if (current->row == p->row && current->col == p->col)
            {
                current->data += p->data;
                p = p->next;
                q->next=p;

            }
            else
            {
                p = p->next;
                q=q->next;
            }
        }
        current = current->next;
    }
    current = objective;
     //*这里可能会存在输出结果顺序不对的情况，故引入change函数纠正输出结果的顺序*//
     //*将链表遍历结点数次数即可，先计算链表结点数*//
    int i=0;
    while(current!=NULL)
    {
        current=current->next;
        i++;
    }
    int j=0;
    //*调用change函数纠正输出顺序*//
    while(j<i)
    {
        change(objective);
        j++;
    }
    current=objective->next;
    while (current != NULL) {
        printf("%d %d %d\n", current->row, current->col, current->data);
        current = current->next;
    }

    return 0;
}
