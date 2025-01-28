#include<stdio.h>
#include<stdlib.h>

int binarySearch(int arr[], int st, int end, int target){
    while(st <= end){
        int mid = st + (end-st)/2;
        if(arr[mid] == target){
            return mid;
        }else if(arr[mid] < target){
            st = mid+1;
        }else{
            end = mid-1;
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

    int foundIndex = binarySearch(arr, 0, n-1, target);

    if(foundIndex == -1){
        printf("Element not found\n");
    }else{
        printf("Element found at : %d\n", foundIndex);
    }

    return 0;
}