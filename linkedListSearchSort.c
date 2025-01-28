#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

Node* createNode(int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Node* head = NULL;

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
    return;
}

void sortLL(){
    Node* i = head;
    Node* j = NULL;
    int temp;
    for(i=head; i->next != NULL; i=i->next){
        for(j=i->next; j != NULL; j=j->next){
            if(i->data > j->data){
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
    return;
}

int getMaxOccElement(){
    sortLL();
    int maxCount = 1;
    int count = 1;
    int maxOccElement = head->data;
    Node* temp = head;
    while(temp->next!=NULL){
        if(temp->data == temp->next->data){
            count++;
        }else{
            if(count > maxCount){
                maxCount = count;
                maxOccElement = temp->data;
            }
            count = 1;
        }
        temp = temp->next;
    }
    return maxOccElement;
}

int searchLL(int target){
    Node* temp = head;
    while(temp != NULL){
        if(temp->data == target){
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

int getMid(){
    Node* slow = head;
    Node* fast = head;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow->data;
}

int getMax(){
    Node* temp = head;
    int max = temp->data;
    while(temp != NULL){
        if(temp->data > max){
            max = temp->data;
        }
        temp = temp->next;
    }
    return max;
}

int getMaxIndex(){
    Node* temp = head;
    int max = getMax();
    int maxIndex = 1;
    // 1 based indexing
    while(temp != NULL){
        if(temp->data == max){
            return maxIndex;
        }
        maxIndex++;
        temp = temp->next;
    }
    return maxIndex;
}

int getFreqOfMax(){
    Node* temp = head;
    int max = getMax();
    int freq = 0;
    while(temp != NULL){
        if(temp->data == max){
            freq++;
        }
        temp = temp->next;
    }
    return freq;
}


int main(){

    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    if(n == 0){
        printf("Empty list\n");
        return 0;
    }

    int data;
    printf("Enter the elements: ");
    for(int i=0; i<n; i++){
        scanf("%d", &data);
        addLast(data);
    }

    printf("Enter the option to perform : \n");
    //main question : 
    printf("1. Get Max Occuring Element\n");
    //extraas
    printf("2. Sort the linked list\n");
    printf("3. Search for presence of an element\n");
    printf("4. Get maximum element in list\n");
    printf("5. Position of maximum element\n");
    printf("6. Get frequency of maximum element\n");
    printf("7. Find mid element\n");
    printf("8. Print the linked list\n");
    int option;
    printf("Enter the option: ");
    scanf("%d", &option);
    switch (option)
    {
    case 1:
        int maxOccuringElement = getMaxOccElement();
        printf("Maximum occuring element is %d\n", maxOccuringElement);
        break;
    case 2:
        sortLL();
        break;
    case 3: 
        printf("Enter the element to search: ");
        int target;
        scanf("%d", &target);
        searchLL(target);
        int found = searchLL(target);
        if(found == 1){
            printf("Element found\n");
        }else{
            printf("Element not found\n");
        }
        break;
    case 4:
        int max = getMax();
        printf("Maximum element in the list is %d\n", max);
        break;
    case 5:
        int maxIndex = getMaxIndex();
        printf("Position of maximum element is %d\n", maxIndex);
        break;
    case 6:
        int freq = getFreqOfMax();
        printf("Frequency of maximum element is %d\n", freq);
        break;
    case 7:
        int midElement = getMid();
        printf("Mid element is %d\n", midElement);
        break;
    case 8:
        printLL();
        break;
    default:
        break;
    }
    return 0;
}