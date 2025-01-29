#include<stdio.h>
#include<stdlib.h>

void merge(int arr[], int st, int mid, int end){
    int n1 = mid - st + 1;
    int n2 = end - mid;
    int left[n1];
    int right[n2];

    for(int i=0; i<n1; i++){
        left[i] = arr[st+i];
    }

    for(int i=0; i<n2; i++){
        right[i] = arr[mid+1+i];
    }

    int i=0, j=0;
    int index = st;
    while(i < n1 && j < n2){
        if(left[i] <= right[j]){
            arr[index] = left[i];
            i++;
        }else{
            arr[index] = right[j];
            j++;
        }
        index++;
    }

    while(i < n1){
        arr[index] = left[i];
        i++;
        index++;
    }

    while(j < n2){
        arr[index] = right[j];
        j++;
        index++;
    }

    return;
}

void mergeSort(int arr[], int st, int end){
    if(st >= end){
        return;
    }
    int mid = st + (end-st)/2;
    mergeSort(arr, st, mid);
    mergeSort(arr, mid+1, end);
    merge(arr, st, mid, end);
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

    mergeSort(arr, 0, n-1);

    printf("sorted array : \n");
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}