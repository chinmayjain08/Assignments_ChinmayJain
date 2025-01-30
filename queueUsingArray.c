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
    printf("%d enqueued\n", data);
    return;
}

void dequeue(){
    if(front > rear){
        printf("queue empty\n");
        return;
    }
    if(front == -1){
        printf("queue empty\n");
        return;
    }
    printf("%d dequeued from queue\n", queue[front++]);
    return;
}

void peek(){
    if(front > rear){
        printf("queue empty\n");
        return;
    }
    if(front == -1){
        printf("queue empty\n");
    }else{
        printf("front element of queue : %d\n", queue[front]);
    }
    return;
}

void printQueue(){
    if(front == -1 || front > rear){
        printf("empty queue\n");
        return;
    }
    printf("elements in queue : \n");
    for(int i=front; i<=rear; i++){
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int sizeQueue(){
    if(front == -1 || front > rear){
        printf("queue empty\n");
        return 0;
    }
    int len = 0;
    for(int i=front; i<=rear; i++){
        len++;
    }
    return len;
}

int main(){

    printf("enter number of operations to perform : ");
    int operations;
    scanf("%d", &operations);

    printf("1. enqueue data to queue\n");
    printf("2. dequeue value out of queue\n");
    printf("3. get front element of queue\n");
    printf("4. print elements of queue\n");
    printf("5. get the size of queue\n");
    int option, data;
    
    for(int i=0; i<operations; i++){
        printf("choose option for operation to perform on stack : ");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            printf("enter value to enqueue : ");
            scanf("%d", &data);
            enqueue(data);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            peek();
            break;
        case 4:
            printQueue();
            break;
        case 5:
            int length = sizeQueue();
            printf("length of queue : %d\n", length);
            break;
        default:
            break;
        }
    }

    return 0;
}