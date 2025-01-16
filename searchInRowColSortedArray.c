#include<stdio.h>
#include<stdlib.h>

int binarySearch(int* nums, int target, int size){
    int s=0;
    int e=size-1;
    
    while(s<=e){
        int mid = s + (e-s)/2;
        if(target == nums[mid]){
            return mid;
        }else if(target < nums[mid]){
            e = mid-1;
        }else{
            s= mid+1;
        }
    }
    
    return -1;
}

int main(){
    
    int n,m, target;
    printf("enter n and m : ");
    scanf("%d %d", &n, &m);
    
    printf("enter target element : ");
    scanf("%d", &target);
    
    int** nums = (int**)malloc(n * sizeof(int*));
    for(int i=0; i<n; i++){
        nums[i] = (int*)malloc(m * sizeof(int));
    }
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf("%d", &nums[i][j]);
        }
    }
    
    int answerRow = -1;
    int answerCol = -1;
    
    for(int i=0; i<n; i++){
        if(target >= nums[i][0] && target <= nums[i][m-1]){
            int foundCol = binarySearch(nums[i], target, m);
            if(foundCol){
                answerRow = i;
                answerCol = foundCol;
                break;
            }else{
                continue;
            }
        }
    }
    
    if(!answerRow && !answerCol){
        printf("element not present");
    }else{
        printf("present in row : %d and column : %d", answerRow+1, answerCol+1);
    }
    
    
    return 0;
}