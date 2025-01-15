#include<stdio.h>
#include<stdlib.h>

void swap(int *num1, int *num2){
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

void reverseArray(int *arr, int size){
    for(int i=0; i<size/2; i++){
        swap((arr+i), (arr + (size-i-1)));
    }
}

void reverseColInMatrix(int **arr, int rows, int colToReverse){
    for(int i=0; i<rows/2; i++){
        int temp = arr[i][colToReverse];
        arr[i][colToReverse] = arr[rows-i-1][colToReverse];
        arr[rows-i-1][colToReverse] = temp;
    }
}

int main(){
    
    int rows;
    printf("enter no. of rows in matrix: ");
    scanf("%d", &rows);
    int cols;
    printf("enter no. of cols in matrix: ");
    scanf("%d", &cols);
    
    int **arr = (int**)malloc(rows * sizeof(int*));
    for(int i=0; i<rows; i++){
        arr[i] = (int*)malloc(cols * sizeof(int));
    }
    
    printf("enter values in matrix : \n");
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            scanf("%d", *(arr+i)+j);
        }
    }
    
    int n = cols;
    for(int i=0; i<rows; i++){
        reverseArray(*(arr+i), n);
    }
    
    for(int i=0; i<cols; i++){
        reverseColInMatrix(arr, rows, i);
    }
    
    printf("180 deg flipped matrix : \n");
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            printf("%d ", *(*(arr+i)+j));
        }
        printf("\n");
    }
    
    return 0;
}