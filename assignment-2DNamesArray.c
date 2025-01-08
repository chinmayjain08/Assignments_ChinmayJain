#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int strLength(char* str){
    int len = 0;
    while(*str){
        len++;
        str++;
    }
    return len;
}

int main() {
    
    int rows;
    int cols;
    
    printf("Enter the number of rows : ");
    scanf("%d", &rows);
    printf("Enter the number of columns : ");
    scanf("%d", &cols);
    
    char*** namesMatrix = (char***)malloc(rows * sizeof(char**));
    for(int i=0; i<rows; i++){
        namesMatrix[i] = (char**)malloc(cols * sizeof(char*));
        for(int j=0; j<cols; j++){
            namesMatrix[i][j] = (char*)malloc(51 * sizeof(char));
        }
    }
    
    int maxLength = 0;
    char* longestName = "";
    int vowelStartingNames = 0;
    
    printf("Enter the names : \n");
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            printf("Name at (%d, %d) : ", i, j);
            scanf("%s", namesMatrix[i][j]);
            int length = strLength(namesMatrix[i][j]);
            if(length > maxLength){
                maxLength = length;
                longestName = namesMatrix[i][j];
            }
            if(namesMatrix[i][j][0] == 'A' || namesMatrix[i][j][0] == 'E' || namesMatrix[i][j][0] == 'I' || namesMatrix[i][j][0] == 'O' || namesMatrix[i][j][0] == 'U' || namesMatrix[i][j][0] == 'a' || namesMatrix[i][j][0] == 'e' || namesMatrix[i][j][0] == 'i' || namesMatrix[i][j][0] == 'o' || namesMatrix[i][j][0] == 'u'){
                vowelStartingNames++;
            }
        }
    }
    
    printf("The 2D array of names is : \n");
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            printf("%s ", namesMatrix[i][j]);
        }
        printf("\n");
    }
    printf("Number of names starting with a vowel : %d\n", vowelStartingNames);
    printf("The longest name : %s\n", longestName);

    return 0;
}