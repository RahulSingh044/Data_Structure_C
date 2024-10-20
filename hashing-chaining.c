#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10

// Structure for a node in the linked list
struct Node {
    int key;
    struct Node *next;
};

// Structure for the hash table
struct HashTable {
    struct Node *table[TABLE_SIZE];
};

// Hash function (simple modulo operation)
int hash(int key) {
    return key % TABLE_SIZE;
}

// Create a new node
struct Node *createNode(int key) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->next = NULL;
    return newNode;
}

// Initialize the hash table
void initHashTable(struct HashTable *ht) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        ht->table[i] = NULL;
    }
}

// Insert a key into the hash table
void insert(struct HashTable *ht, int key) {
    int index = hash(key);
    struct Node *newNode = createNode(key);

    if (ht->table[index] == NULL) {
        ht->table[index] = newNode;
    } else {
        struct Node *temp = ht->table[index];
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Search for a key in the hash table
int search(struct HashTable *ht, int key) {
    int index = hash(key);
    struct Node *temp = ht->table[index];

    while (temp != NULL) {
        if (temp->key == key) {
            return 1; // Key found
        }
        temp = temp->next;
    }
    return 0; // Key not found
}

// Display the hash table
void display(struct HashTable *ht) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("Index %d: ", i);
        struct Node *temp = ht->table[i];
        while (temp != NULL) {
            printf("%d -> ", temp->key);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main() {
    struct HashTable ht;
    initHashTable(&ht);

    insert(&ht, 12);
    insert(&ht, 22);
    insert(&ht, 2);
    insert(&ht, 13);

    display(&ht);

    printf("Search 22: %d\n", search(&ht, 22));
    printf("Search 10: %d\n", search(&ht, 10));

    return 0;
}
