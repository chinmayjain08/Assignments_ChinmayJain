#include<stdio.h>
#include<stdlib.h>

int minimumOfRow(int* arr, int n, int *index){
    int minNum = arr[0];
    for(int i=1; i<n; i++){
        if(arr[i] < minNum){
            minNum = arr[i];
            *index = i;
        }
    }
    return minNum;
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
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf("%d", &nums[i][j]);
        }
    }

    int saddlePoint = -1;
    for(int i=0; i<n; i++){
        int minIdx = 0;
        int minNum = minimumOfRow(nums[i], m, &minIdx);
        
        saddlePoint = minNum;
            for(int k=0; k<n; k++){
                if(nums[k][minIdx] > minNum){
                    saddlePoint = -1;
                    break;
                }
            }
            if(saddlePoint != -1){
                printf("Saddle point is %d\n", saddlePoint);
                return 0;
            }
    }
    
    printf("Saddle point is %d\n", saddlePoint);

    return 0;
}