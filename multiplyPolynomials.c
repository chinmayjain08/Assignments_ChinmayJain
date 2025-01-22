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

void printPolynomial(struct Node* head) {
    struct Node* temp = head;
    if(head == NULL){
        printf("0\n");
        return;
    }   
    while (temp != NULL) {
        if(temp->power > 0){
            printf("%dx^%d", temp->coeff, temp->power);
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
    
    return result->next;
}


int main(){
    
    struct Node* head1 = createNode(3,2);
    struct Node* sec1 = createNode(3,1);
    struct Node* third1 = createNode(1,0);
    struct Node* head2 = createNode(1,2);
    struct Node* sec2 = createNode(4,1);
    struct Node* third2 = createNode(3,0);

    head1->next = sec1;
    sec1->next = third1;
    third1->next = NULL;

    head2->next = sec2;
    sec2->next = third2;
    third2->next = NULL;
    
    struct Node* result = multiplyPolynomial(head1, head2);
    printPolynomial(result);
    
    return 0;
}
