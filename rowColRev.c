#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void reverseCols(int** matrix, int rows, int colToRev){
    for(int i=0; i<rows/2; i++){
        int temp = matrix[i][colToRev];
        matrix[i][colToRev] = matrix[rows-i-1][colToRev];
        matrix[rows-i-1][colToRev] = temp;
    }
}

void reverseRows(int** matrix, int cols, int rowToRev){
    for(int i=0; i<cols/2; i++){
        int temp = matrix[rowToRev][i];
        matrix[rowToRev][i] = matrix[rowToRev][cols-i-1];
        matrix[rowToRev][cols-i-1] = temp;
    }
}

int main(){
    
    // char* str = (char*)malloc(1001 * sizeof(char));
    // fgets(str, 1001, stdin);
    // str[strcspn(str, "\n")] = '\0';
    
    int rows, cols;
    scanf("%d %d", &rows, &cols);
    
    int** matrix = (int**)malloc(rows * sizeof(int*));
    for(int i=0; i<rows; i++){
        *(matrix+i) = (int*)malloc(cols * sizeof(int));
    }
    
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            scanf("%d", (*(matrix+i)+j));
        }
    }
    
    // for(int i=0; i<rows; i++){
    //     for(int j=0; j<cols; j++){
    //         printf("%d", *(*(matrix+i)+j));
    //     }
    // }
    
    // for(int i=0; i<cols; i++){
    //     reverseCols(matrix, rows, i);
    // }
    
    for(int i=0; i<rows; i++){
        reverseRows(matrix, cols, i);
    }
    
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            printf("%d ", *(*(matrix+i)+j));
        }
        printf("\n");
    }
    
    
    return 0;
}