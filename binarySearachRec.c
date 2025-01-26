#include<stdio.h>
#include<stdlib.h>

int binarySearch(int arr[], int st, int end, int target){
    if(st > end){
        return -1;
    }

    int mid = (st+end)/2;
    if(arr[mid] == target){
        return mid;
    }

    if(arr[mid] > target){
        return binarySearch(arr, st, mid-1, target);
    }
    if(arr[mid] < target){
        return binarySearch(arr, mid+1, end, target);
    }
}

int main(){
    int size;
    printf("total elements : ");
    scanf("%d", &size);

    printf("enter elements in array\n");
    int arr[size];
    for(int i=0; i<size; i++){
        scanf("%d", &arr[i]);
    }

    printf("enter number to search : ");
    int target;
    scanf("%d", &target);

    int st = 0;
    int end = size-1;

    int ans = binarySearch(arr, st, end, target);

    if(ans >= 0){
        printf("target found at index %d\n", ans);
    }else{
        printf("target not found\n");
    }

    return 0;
}