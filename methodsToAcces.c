#include<stdio.h>
#include<stdlib.h>


void method1(int rows, int cols, int arr[rows][cols]){
    printf("method1 : \n");
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void method2(int* arr, int rows, int cols){
    printf("method2 : \n");

    for(int i=0; i<(rows*cols); i++){
        printf("%d ", *(arr+i));
    }
    printf("\n");
    printf("\n");
}

void method3(int rows, int cols, int arr[rows][cols]){
    printf("method3 : \n");
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            printf("%d ", *(*(arr+i)+j));
        }
        printf("\n");
    }
    printf("\n");
}


int main(){

    int rows = 3;
    int cols = 3;

    // int** matrix = (int**)malloc(rows * sizeof(int*));
    // for(int i=0; i<rows; i++){
    //     matrix[i] = (int*)malloc(cols * sizeof(int));
    // }

    int matrix[3][3] = {
        {1,2,3},
        {4,5,6},
        {7,8,9}};

    printf("enter matrix elements: \n");
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            scanf("%d", &matrix[i][j]);
        }
    }

    int *ptr = &matrix[0][0];

    method1(rows, cols, matrix);
    method2(ptr, rows, cols);
    method3(rows, cols, matrix);

    return 0;
}