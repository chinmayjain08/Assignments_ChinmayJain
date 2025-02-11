#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int hashTable[100001] = {0};

int search(int key){
    if(hashTable[key] != 0){
        return 1;
    }
    return 0;
}

int findXOR(int arr[], int n, int target){
    for(int i=0; i<n; i++){
        int toFind = target^arr[i];
        if(search(toFind)){
            printf("%d %d", toFind, arr[i]);
            return 1;
        }else{
            hashTable[arr[i]] = 1;
        }
    }
    return 0;
}

int main() {
    
    int n;
    printf("enter n : ");
    scanf("%d", &n);
    
    int arr[n];
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    
    int target;
    printf("enter target : ");
    scanf("%d", &target);
    
    int ans = findXOR(arr, n, target);
    if(!ans){
        printf("no pair for target XOR\n");
    }
    return 0;
}