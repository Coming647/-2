#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

void insertNode(Node* head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = head->prev;
    newNode->next = head;
    head->prev->next = newNode;
    head->prev = newNode;
}

void deleteList(Node* head) {
    Node* current = head->next;
    while (current != head) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
    head->prev = head;
    head->next = head;
}

void calculatePI(int n) {
    Node* head = (Node*)malloc(sizeof(Node));
    head->prev = head;
    head->next = head;

    insertNode(head, 3); // Initialize with 3 before decimal point

    for (int i = 0; i < n; i++) {
        insertNode(head, 0); // Initialize decimal points
    }

    insertNode(head, 1); // Initialize with 1 after decimal point

    // Perform calculations for PI here

    // Output PI value
    Node* current = head->next;
    while (current != head) {
        if (current->data == 0) {
            printf(".");
        } else {
            printf("%d", current->data);
        }
        current = current->next;
    }
    printf("\n");

    deleteList(head);
}

int main() {
    int n;
    printf("请输入要计算的PI值的小数点后位数：");
    scanf("%d", &n);

    calculatePI(n);

    return 0;
}
