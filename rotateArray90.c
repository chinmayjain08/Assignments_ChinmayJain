#include<stdio.h>
#include<stdlib.h>

void reverse(int* arr, int n){
    for(int i=0; i<n/2; i++){
        int temp = arr[i];
        arr[i] = arr[n-i-1];
        arr[n-i-1] = temp;
    }
}

int main(){

    int n, m;
    printf("Enter the number of rows and columns\n");
    scanf("%d", &n);
    scanf("%d", &m);

    int** nums = (int**)malloc(n * sizeof(int*));
    for(int i=0; i<n; i++){
        nums[i] = (int*)malloc(m * sizeof(int));
    }

    printf("Enter the elements in matrix\n");
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf("%d", &nums[i][j]);
        }
    }

    //transpose
    for(int i=0; i<n; i++){
        for(int j=i; j<m; j++){
            int temp = nums[i][j];
            nums[i][j] = nums[j][i];
            nums[j][i] = temp;
        }
    }

    //reverse
    for(int i=0; i<n; i++){
        reverse(nums[i], m);
    }

    printf("Matrix : \n");
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            printf("%d ", nums[i][j]);
        }
        printf("\n");
    }

    return 0;
}