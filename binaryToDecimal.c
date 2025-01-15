// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>

void convertToDecimal(int* nums){
    int binary = 0;
    for(int i=0; i<8; i++){
        binary = binary*10 + (nums[i]);
    }
    int temp = binary;
    int base = 1;
    int decimal = 0;
    while(temp){
        int lastDigit = temp%10;
        temp = temp / 10;
        decimal += lastDigit * base;
        base *= 2;
    }
    printf("%d\n", decimal);
}

int main() {
    int nums;
    scanf("%d", &nums);
    int** binaryNums = (int**)malloc(nums * sizeof(int*));
    for(int i=0; i<nums; i++){
        (*(binaryNums+i)) = (int*)malloc(8 * sizeof(int));
    }
    
    for(int i=0; i<nums; i++){
        for(int j=0; j<8; j++){
            scanf("%d", (*(binaryNums+i) + j));
        }
    }
    
    // for(int i=0; i<nums; i++){
    //     for(int j=0; j<8; j++){
    //         printf("%d", *(*(binaryNums+i) + j));
    //     }
    //     printf("\n")
    // }
    
    for(int i=0; i<nums; i++){
        convertToDecimal(*(binaryNums+i));
    }

    return 0;
}