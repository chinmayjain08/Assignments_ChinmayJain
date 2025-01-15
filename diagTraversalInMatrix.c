#include<stdio.h>
#include<stdlib.h>

int main(){
    int order;
    printf("enter order of matrix: ");
    scanf("%d", &order);
    
    int **arr = (int**)malloc(order * sizeof(int*));
    for(int i=0; i<order; i++){
        arr[i] = (int*)malloc(order * sizeof(int));
    }
    
    printf("enter values in matrix : \n");
    for(int i=0; i<order; i++){
        for(int j=0; j<order; j++){
            scanf("%d", *(arr+i)+j);
        }
    }
    
    printf("diagnol traversal of elements : \n");
    for(int i=0; i<order; i++){
        int index = 0;
        printf("%d ", *(*(arr+i) + index));
        int tempInd = i;
        while(tempInd>0 && index<order-1){
            printf("%d ", *(*(arr+tempInd-1) + (index+1)));
            tempInd--;
            index++;
        }
        printf("\n");
    }
    
    for(int i=1; i<order; i++){
        int index = i;
        int row = order-1;
        printf("%d ", arr[row][index]);
        while(index<order-1 && row>0){
            printf("%d ", arr[row-1][index+1]);
            row--;
            index++;
        }
        printf("\n");
    }
}