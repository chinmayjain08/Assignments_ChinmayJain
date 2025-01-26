#include<stdio.h>
#include<stdlib.h>


int checkSorted(int arr[], int index, int size){
    if(index >= size){
        return 1;
    }

    if(arr[index-1] > arr[index]){
        return 0;
    }

    return checkSorted(arr, index+1, size);
}


int main(){
    int size;
    printf("total elements : ");
    scanf("%d", &size);

    if(size == 0){
        printf("array is sorted\n");
        return 0;
    }

    printf("enter elements in array\n");
    int arr[size];
    for(int i=0; i<size; i++){
        scanf("%d", &arr[i]);
    }

    int index = 1;

    int ans = checkSorted(arr, index, size);

    if(ans){
        printf("array is sorted\n");
    }else{
        printf("array not sorted\n");
    }

    return 0;
}