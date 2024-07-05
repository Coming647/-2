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
    //*�������Ŀ�������ֱ�Ӵ���a��b����*//
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

    //*������a��b�����ֱ�Ӵ���Ŀ������objective*//
    struct Node* objective=(struct Node*)malloc(sizeof(struct Node));
    objective->next=NULL;
    struct Node* current = (struct Node*)malloc(sizeof(struct Node));
    current=objective;
    //*���ھ���˷��д������������ӵĲ��裬��������ֿ����㣬��������п��ܴ���������*//
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
    //*Ȼ��������ӵ������ע��Ҫ����Ҫ�ӵ�Ԫ����Ӻ�Ҫɾ��һЩͬ��ͬ�е�Ԫ��*//
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
     //*������ܻ����������˳�򲻶Ե������������change����������������˳��*//
     //*���������������������ɣ��ȼ�����������*//
    int i=0;
    while(current!=NULL)
    {
        current=current->next;
        i++;
    }
    int j=0;
    //*����change�����������˳��*//
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
