#include <stdio.h>
#include <stdlib.h>
//*首先创建十字链表*//
struct Node {
    int row;
    int col;
    int data;
    struct Node* nextRow;
    struct Node* nextCol;
};


 //*设立循环进行遍历十字链表如果符合条件就相加到第3个十字链表中*//
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
//*再将a，b链表中没有遍历的元素插入到结果链表中*//
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
