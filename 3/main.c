#include <stdio.h>
#include <stdlib.h>
//*���ȴ���ʮ������*//
struct Node {
    int row;
    int col;
    int data;
    struct Node* nextRow;
    struct Node* nextCol;
};


 //*����ѭ�����б���ʮ���������������������ӵ���3��ʮ��������*//
void add(struct Node* A, struct Node* B) {
    struct Node* resultHeader = NULL;
    struct Node* currentA = A;
    struct Node* currentB = B;

    while (currentA != NULL && currentB != NULL) {
        if (currentA->row < currentB->row || (currentA->row == currentB->row && currentA->col < currentB->col)) {
            struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->row = currentA ->row;
        newNode->col = currentA ->col;
        newNode->data = currentA ->data;
        newNode->nextRow = NULL;
        newNode->nextCol = NULL;

        if (resultHeader == NULL) {
            resultHeader = newNode;
        } else {
            struct Node* current = resultHeader;
            while (current->nextRow != NULL) {
                current = current->nextRow;
            }
            current->nextRow = newNode;

            current = resultHeader;
            while (current->nextCol != NULL) {
                current = current->nextCol;
            }
            current->nextCol = newNode;
        }
            currentA = currentA->nextRow;
        } else if (currentA->row > currentB->row || (currentA->row == currentB->row && currentA->col > currentB->col)) {
            struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->row = currentB->row;
        newNode->col = currentB->col;
        newNode->data = currentB->data;
        newNode->nextRow = NULL;
        newNode->nextCol = NULL;

        if (resultHeader == NULL) {
            resultHeader = newNode;
        } else {
            struct Node* current = resultHeader;
            while (current->nextRow != NULL) {
                current = current->nextRow;
            }
            current->nextRow = newNode;

            current = resultHeader;
            while (current->nextCol != NULL) {
                current = current->nextCol;
            }
            current->nextCol = newNode;
        }
            currentB = currentB->nextRow;
        } else {
            int sum = currentA->data + currentB->data;
            if (sum != 0) {
                struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->row = currentA ->row;
        newNode->col = currentA ->col;
        newNode->data = sum;
        newNode->nextRow = NULL;
        newNode->nextCol = NULL;

        if (resultHeader == NULL) {
            resultHeader = newNode;
        } else {
            struct Node* current = resultHeader;
            while (current->nextRow != NULL) {
                current = current->nextRow;
            }
            current->nextRow = newNode;

            current = resultHeader;
            while (current->nextCol != NULL) {
                current = current->nextCol;
            }
            current->nextCol = newNode;
        }
            }
            currentA = currentA->nextRow;
            currentB = currentB->nextRow;
        }
    }
//*�ٽ�a��b������û�б�����Ԫ�ز��뵽���������*//
    while (currentA != NULL) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->row = currentA ->row;
        newNode->col = currentA ->col;
        newNode->data = currentA ->data;
        newNode->nextRow = NULL;
        newNode->nextCol = NULL;

        if (resultHeader == NULL) {
            resultHeader = newNode;
        } else {
            struct Node* current = resultHeader;
            while (current->nextRow != NULL) {
                current = current->nextRow;
            }
            current->nextRow = newNode;

            current = resultHeader;
            while (current->nextCol != NULL) {
                current = current->nextCol;
            }
            current->nextCol = newNode;
        }
        currentA = currentA->nextRow;
    }

    while (currentB != NULL) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->row = currentB->row;
        newNode->col = currentB->col;
        newNode->data = currentB->data;
        newNode->nextRow = NULL;
        newNode->nextCol = NULL;

        if (resultHeader == NULL) {
            resultHeader = newNode;
        } else {
            struct Node* current = resultHeader;
            while (current->nextRow != NULL) {
                current = current->nextRow;
            }
            current->nextRow = newNode;

            current = resultHeader;
            while (current->nextCol != NULL) {
                current = current->nextCol;
            }
            current->nextCol = newNode;
        }
        currentB = currentB->nextRow;
    }
   //*���Ŀ��ʮ������*//
    struct Node* current = resultHeader;
    while (current != NULL) {
        printf("%d %d %d\n", current->row, current->col, current->data);
        struct Node* temp = current;
        current = current->nextRow;
        free(temp);
    }
}

int main() {
    int m, n, t1, t2;
    scanf("%d %d %d %d", &m, &n, &t1, &t2);
//*������������������ʼ����a��bʮ������*//
    struct Node* A = NULL;
    struct Node* B = NULL;

    for (int i = 0; i < t1; i++) {
        int row, col, data;
        scanf("%d %d %d", &row, &col, &data);

        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->row = row;
        newNode->col = col;
        newNode->data = data;
        newNode->nextRow = NULL;
        newNode->nextCol = NULL;

        if (A == NULL) {
            A = newNode;
        } else {
            struct Node* current = A;
            while (current->nextRow != NULL) {
                current = current->nextRow;
            }
            current->nextRow = newNode;

            current = A;
            while (current->nextCol != NULL) {
                current = current->nextCol;
            }
            current->nextCol = newNode;
        }
    }

    for (int i = 0; i < t2; i++) {
        int row, col, data;
        scanf("%d %d %d", &row, &col, &data);

        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->row = row;
        newNode->col = col;
        newNode->data = data;
        newNode->nextRow = NULL;
        newNode->nextCol = NULL;

        if (B == NULL) {
            B = newNode;
        } else {
            struct Node* current = B;
            while (current->nextRow != NULL) {
                current = current->nextRow;
            }
            current->nextRow = newNode;

            current = B;
            while (current->nextCol != NULL) {
                current = current->nextCol;
            }
            current->nextCol = newNode;
        }
    }
//*������a��b������ֱ�ӵ���add����ʹ������������Ȼ�����*//
    add(A, B);

    return 0;
}
