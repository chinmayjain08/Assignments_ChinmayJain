#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isSorted(int n, int* arr){
    if(n==0 || n==1) return true;
    return arr[n-1] >= arr[n-2] && isSorted(n-1, arr);
}

int main() {
    
    int arr[] = {1,2,4,3,5};
    bool ans = isSorted(5, arr);
    
    if(ans){
        printf("sorted\n");
    }else{
        printf("not sorted\n");
    }

    return 0;
}