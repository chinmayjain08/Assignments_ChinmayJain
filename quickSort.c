#include<stdio.h>
#include<stdlib.h>

void swap(int*num1, int*num2){
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int index = low - 1;
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            index++;
            swap(&arr[index], &arr[j]);
        }
    }
    swap(&arr[index + 1], &arr[high]);  
    return index + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivotIdx = partition(arr, low, high);
        quickSort(arr, low, pivotIdx - 1);
        quickSort(arr, pivotIdx + 1, high);
    }
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

    quickSort(arr, 0, n-1);

    printf("sorted array : \n");
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}