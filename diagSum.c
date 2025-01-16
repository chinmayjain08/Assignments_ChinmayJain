// Online C compiler to run C program online
#include <stdio.h>

int main() {
    
    int n;
    scanf("%d", &n);
    int matrix[n][n];
    
    int diagSum = 0;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d", &matrix[i][j]);
        }
    }
    
    for(int i=0; i<n; i++){
        diagSum+=matrix[i][i];
        //primary
        diagSum+=matrix[n-i-1][i];
        //secondary
    }
    
    if(n % 2 != 0){
        diagSum -= matrix[n/2][n/2];
    }
    
    
    printf("%d\n", diagSum);

    return 0;
}