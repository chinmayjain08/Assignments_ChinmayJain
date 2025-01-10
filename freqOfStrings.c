#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
    // char string[100];
    char *string;
    int count;
}FreqInfo;

void updateFreq(char* str, FreqInfo* freq, int* index, int n, int m){
    
    int size = n*m;
    int present = 0;
    for(int i=0; i < *index; i++){
        //traversing to index only as memory not allocated further
        if(strcmp(str, freq[i].string) == 0){
            freq[i].count += 1;
            present = 1;
            break;
        }
    }
    
    if(!present){
        freq[*index].string = (char*)malloc(100 * sizeof(char));
        //memory allocated to string
        strcpy(freq[*index].string, str);
        freq[*index].count = 1;
        (*index)++;
    }
    
}

void calculateFreqOfStrings(char*** matrix, int rows, int cols){
    FreqInfo* frequency = (FreqInfo*)malloc((rows * cols) * sizeof(FreqInfo));
    //if we allocate all strings here then no need to do for individual in updateFreq
    // for(int i=0; i<(rows*cols); i++){
    //     frequency[i].string = (char*)malloc(100 * sizeof(char));
    // }
    int index = 0;
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            updateFreq(matrix[i][j], frequency, &index, rows, cols);
        }
    }
    for(int i=0; i<index; i++){
        printf("string : %s\n", (frequency+i)->string);
        printf("count : %d\n", (frequency+i)->count);
    }
}

int main() {
    
    int n, m;
    printf("enter rows and cols : ");
    scanf("%d %d", &n, &m);
    
    char*** matrix = (char***)malloc(n * sizeof(char**));
    for(int i=0; i<n; i++){
        matrix[i] = (char**)malloc(m * sizeof(char*));
        for(int j=0; j<m; j++){
            matrix[i][j] = (char*)malloc(100 * sizeof(char));
        }
    }
    
    printf("enter elements: \n");
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf("%s", matrix[i][j]);
        }
    }

    // for(int i=0; i<n; i++){
    //     for(int j=0; j<m; j++){
    //         printf("%s ", matrix[i][j]);
    //     }
    //     printf("\n");
    // }
    
    calculateFreqOfStrings(matrix, n, m);

    return 0;
}