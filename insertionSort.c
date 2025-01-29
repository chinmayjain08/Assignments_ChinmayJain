#include<stdio.h>
#include<stdlib.h>

void insertionSort(int arr[], int size){
    int curr, j;
    //j to compare the current element with the previous elements
    for(int i=1; i<size; i++){
        curr = arr[i];
        j = i-1;
        while(j >= 0 && arr[j] > curr){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = curr;
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

    insertionSort(arr, n);

    printf("sorted array : \n");
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}