#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10

struct Node {
    int key;
    struct Node *next;
};

struct HashTable {
    struct Node* table[TABLE_SIZE];
};

int hashFunction(int key) {
    return key % TABLE_SIZE;
}

struct HashTable* createHashTable() {
    struct HashTable* ht = (struct HashTable*)malloc(sizeof(struct HashTable));
    for (int i = 0; i < TABLE_SIZE; i++) {
        ht->table[i] = NULL;
    }
    return ht;
}

void insert(struct HashTable* ht, int key) {
    int index = hashFunction(key);
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->next = ht->table[index];
    ht->table[index] = newNode;
}

int ASL1(struct HashTable* ht) {
    int totalASL = 0;
    int totalCount = 0;

    for (int i = 0; i < TABLE_SIZE; i++) {
        int count = 0;
        struct Node* current = ht->table[i];
        while (current != NULL) {
            count++;
            current = current->next;
        }
        totalASL += (count * (count + 1)) / 2;
        totalCount += count;
    }

    return totalASL / totalCount;
}

int main() {
    struct HashTable* ht = createHashTable();

    insert(ht, 10);
    insert(ht, 20);
    insert(ht, 30);
    insert(ht, 15);

    int avgASL = ASL1(ht);
    printf("Average Successful Search Length: %d\n", avgASL);

    return 0;
}
