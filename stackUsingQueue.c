#include<stdio.h>
#include<stdlib.h>

int queue[1000001];
int front = -1;
int rear = -1;

void enqueue(int data){
    if(front == -1){
        front = 0;
    }
    queue[++rear] = data;
    return;
}

void dequeue(){
    if(front > rear){
        front = rear = -1;
        printf("stack empty\n");
        return;
    }
    if(front == -1){
        printf("stack empty\n");
        return;
    }
    front++;
    return;
}

int peek(){
    if(front > rear){
        printf("stack empty\n");
        return -1;
    }
    if(front == -1){
        printf("stack empty\n");
        return -1;
    }else{
        return queue[front];
    }
}

void printQueue(){
    if(front == -1 || front > rear){
        printf("empty stack\n");
        return;
    }
    printf("elements in stack : \n");
    for(int i=front; i<=rear; i++){
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int sizeQueue(){
    return (front == -1 || front > rear) ? 0 : (rear - front + 1);
}


// STACK IMPLEMENTATION USING QUEUE

void pushUsingQueue(int data){
    int size = sizeQueue();
    enqueue(data);
    for(int i=0; i<size; i++){
        enqueue(peek());
        dequeue();
    }
    printf("%d pushed in the stack\n", data);
}

void popUsingQueue(){
    dequeue();
    printf("popped\n");
    return;
}

void peekUsingQueue(){
    int top = peek();
    if(top != -1){
        printf("top element of stack : %d\n", top);
    }
    return;
}

void printStackusingQueue(){
    printQueue();
    return;
}

int sizeStack(){
    int size = sizeQueue();
    return size;
}

int main(){

    printf("enter number of operations to perform : ");
    int operations;
    scanf("%d", &operations);

    printf("1. push data to stack\n");
    printf("2. pop value out of stack\n");
    printf("3. top element of stack\n");
    printf("4. print elements of stack\n");
    printf("5. get the size of stack\n");
    int option, data, length;
    
    for(int i=0; i<operations; i++){
        printf("choose option for operation to perform on stack : ");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            printf("enter value to push : ");
            scanf("%d", &data);
            pushUsingQueue(data);
            break;
        case 2:
            popUsingQueue();
            break;
        case 3:
            peekUsingQueue();
            break;
        case 4:
            printStackusingQueue();
            break;
        case 5:
            length = sizeStack();
            printf("size of stack : %d\n", length);
            break;
        default:
            break;
        }
    }

    return 0;
}