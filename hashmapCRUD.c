#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10

typedef struct Node{
    int key;
    int value;
    struct Node* next;
}Node;

Node* hashTable[TABLE_SIZE];

//hash function
int hashFunction(int key) {
    return key % TABLE_SIZE;
}

void insert(int key, int value) {
    int index = hashFunction(key);
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->value = value;
    newNode->next = NULL;
    
    if (hashTable[index] == NULL) {
        hashTable[index] = newNode;
    } else {
        Node* temp = hashTable[index];
        while (temp) {
            if (temp->key == key) {
                temp->value = value;
                free(newNode);
                return;
            }
            if (temp->next == NULL) break;
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

int search(int key) {
    int index = hashFunction(key);
    Node* temp = hashTable[index];
    while (temp) {
        if (temp->key == key) {
            return temp->value;
        }
        temp = temp->next;
    }
    return -1;
}

void delete(int key) {
    int index = hashFunction(key);
    Node* temp = hashTable[index];
    Node* prev = NULL;
    
    while (temp) {
        if (temp->key == key) {
            if (prev == NULL) {
                hashTable[index] = temp->next;
            } else {
                prev->next = temp->next;
            }
            free(temp);
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    
    printf("id not present\n");
    return;
}

void display() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("Bucket %d: ", i);
        Node* temp = hashTable[i];
        while (temp) {
            printf("(%d, %d) -> ", temp->key, temp->value);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main() {
    int choice, key, value;
    while (1) {
        printf("\nHash Map Operations:\n");
        printf("1. Insert (Put)\n2. Search (Get)\n3. Delete (Remove)\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter key: ");
                scanf("%d", &key);
                printf("Enter value: ");
                scanf("%d", &value);
                insert(key, value);
                break;
            case 2:
                printf("Enter key to search: ");
                scanf("%d", &key);
                value = search(key);
                if (value == -1)
                    printf("Key not found.\n");
                else
                    printf("Value: %d\n", value);
                break;
            case 3:
                printf("Enter key to delete: ");
                scanf("%d", &key);
                delete(key);
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
