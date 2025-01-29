#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

Node* head = NULL;

Node* createNode(int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void addLast(int data){
    Node* newNode = createNode(data);
    if(head == NULL){
        head = newNode;
        return;
    }
    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = NULL;
    return;
}

void printLL(){
    Node* temp = head;
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void swap(int* num1, int* num2){
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

void bubbleSort(struct Node* head) {
    if (head == NULL) return;

    struct Node* current;
    struct Node* end = NULL;

    int swapped = 0;

    do {
        swapped = 0;
        current = head;
        while (current->next != end) {
            if (current->data > current->next->data) {
                swap(&current->data, &current->next->data);
                swapped = 1;
            }
            current = current->next;
        }
        end = current;
    } while (swapped);
}

void transformLL(){
    if(head == NULL)return;

    Node* temp = head;
    Node* list3 = NULL;
    Node* list5 = NULL;
    Node* other = NULL;

    Node* list3Head = NULL;
    Node* list5Head = NULL;
    Node* otherHead = NULL;
    
    //break 1 LL into 3 needed lists
    while(temp != NULL){
        if(temp->data % 3 == 0){
            if(!list3){
                list3 = temp;
                list3Head = temp;
            }
            else list3->next = temp;
            list3 = temp;
        }else if(temp->data % 5 == 0){
            if(!list5){
                list5 = temp;
                list5Head = temp;
            }
            else list5->next = temp;
            list5 = temp;
        }else{
            if(!other){
                other = temp;
                otherHead = temp;
            }
            else other->next = temp;
            other = temp;
        }
        temp = temp->next;
    }

    if(list3)list3->next = NULL;
    if(list5)list5->next = NULL;
    if(other)other->next = NULL;

    //sort the 3 arrays
    bubbleSort(list3);
    bubbleSort(list5);
    bubbleSort(other);

    //merge all 3 sorted arrays in required order 
    //3 --> 5 --> others
    Node* mergedHead = NULL;
    temp = mergedHead;

    if(list3Head){
        mergedHead = list3Head;
        temp = list3Head;
        while(temp->next != NULL){
            temp = temp->next;
        }
    }

    if(list5){
        if(!mergedHead){
            mergedHead = list5Head;
            temp = list5Head;
        }else{
            temp->next = list5Head;
        }
        while(temp->next != NULL){
            temp = temp->next;
        }
    }

    if(other){
        if(!mergedHead){
            mergedHead = otherHead;
            temp = otherHead;
        }else{
            temp->next = otherHead;
        }
    }

    head = mergedHead;
}

int main(){

    int size;
    printf("enter size of LL : ");
    scanf("%d", &size);

    printf("enter elements : ");
    int data;
    for(int i=0; i<size; i++){
        scanf("%d", &data);
        addLast(data);
    }

    transformLL();
    printLL();

    return 0;
}