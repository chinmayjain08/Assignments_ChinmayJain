#include<stdio.h>
#include<stdlib.h>

int twoPointerSearch(int arr[], int st, int end, int target){
    while(st <= end){
        if(arr[st] == target){
            return st;
        }else if(arr[end] == target){
            return end;
        }else{
            st++;
            end--;
        }
    }
    return -1;
}

int main(){

    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    int arr[n];
    printf("Enter the elements: ");
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }

    int target;
    printf("Enter the element to search: ");
    scanf("%d", &target);

    int foundIndex = twoPointerSearch(arr, 0, n-1, target);

    if(foundIndex == -1){
        printf("Element not found\n");
    }else{
        printf("Element found at index %d\n", foundIndex);
    }

    return 0;
}