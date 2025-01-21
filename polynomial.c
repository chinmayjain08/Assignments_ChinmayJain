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


struct Node* addPolynomial(struct Node* head1, struct Node* head2){
    struct Node* result = createNode(0,0);
    struct Node* temp = result;

    if(head1 == NULL && head2 != NULL){
        return head2;
    }

    if(head2 == NULL && head1 != NULL){
        return head1;
    }

    while(head1 != NULL && head2 != NULL){
        if(head1->power > head2->power){
            temp->next = head1;
            temp = temp->next;
            head1 = head1->next;
        }else if(head2->power > head1->power){
            temp->next = head2;
            temp = temp->next;
            head1 = head1->next;
        }else{
            int sum = (head1->coeff + head2->coeff);
            struct Node* newNode = createNode(sum, head1->power);
            temp->next = newNode;
            temp = temp->next;
            head1 = head1->next;
            head2 = head2->next;
        }
    }

    while(head1 != NULL){
        temp->next = head1;
        temp = temp->next;
        head1 = head1->next;
    }

    while(head2 != NULL){
        temp->next = head2;
        temp = temp->next;
        head2 = head2->next;
    }

    return result->next;
}

void printPolynomial(struct Node* head) {
    struct Node* temp = head;
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

    struct Node* result = addPolynomial(head1, head2);

    printPolynomial(result);

    return 0;
}