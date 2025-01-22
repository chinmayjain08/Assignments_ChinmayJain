#include<stdio.h>
#include<stdlib.h>

struct Node{
    int coeff;
    int power;
    struct Node* next;
};

struct Node* createNode(int coeff, int power){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = coeff;
    newNode->power = power;
    newNode->next = NULL;
    return newNode;
}

struct Node* addLast(struct Node* head, int coeff, int power){
    struct Node* newNode = createNode(coeff, power);
    if(head == NULL){
        head = newNode;
        return head;
    }
    struct Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = NULL;
    return head;
}

void printPolynomial(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        if(temp->power > 0){
            if(temp->power == 1){
                printf("%dx", temp->coeff);
            }else{
                printf("%dx^%d", temp->coeff, temp->power);
            }
        }else{
            printf("%d", temp->coeff);
        }
        if (temp->next != NULL) {
            printf(" + ");
        }
        temp = temp->next;
    }
    printf("\n");
}

struct Node* addSamePower(struct Node* head){
    if(head == NULL)return head;
    
    struct Node* temp = head;
    int maxPower = 0;
    while(temp != NULL){
        if(temp->power > maxPower){
            maxPower = temp->power;
        }
        temp = temp->next;
    }
    
    int arr[maxPower+1];
    for(int i=0; i<=maxPower; i++){
        arr[i] = 0;
    }
    
    temp = head;
    while(temp != NULL){
        arr[temp->power] += temp->coeff;
        temp = temp->next;
    }
    
    struct Node* result = NULL;
    for(int i=maxPower; i>=0; i--){
        if(arr[i] > 0){
            result = addLast(result, arr[i], i);
        }
    }
    return result;
}

struct Node* multiplyPolynomial(struct Node* head1, struct Node* head2){
    struct Node* result = createNode(0,0);
    struct Node* temp = result;
    struct Node* sec = head2;
    
    while(head1 != NULL){
        head2 = sec;
        while(head2 != NULL){
            int product = head1->coeff * head2->coeff;
            int proPower = head1->power + head2->power;
            struct Node* newNode = createNode(product, proPower);
            temp->next = newNode;
            temp = newNode;
            head2 = head2->next;
        }
        head1 = head1->next;
    }
    
    //combine the added ones
    struct Node* ans = addSamePower(result->next);
    
    return ans;
}


int main(){
    
    struct Node* head1 = createNode(2,2);
    struct Node* sec1 = createNode(3,1);
    struct Node* third1 = createNode(4,0);
    struct Node* head2 = createNode(1,1);
    struct Node* sec2 = createNode(1,0);
    // struct Node* third2 = createNode(3,0);

    head1->next = sec1;
    sec1->next = third1;
    third1->next = NULL;

    head2->next = sec2;
    sec2->next = NULL;
    // third2->next = NULL;
    
    struct Node* result = multiplyPolynomial(head1, head2);
    printPolynomial(result);
    
    return 0;
}