// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>

int reverse(int num){
    int ans = 0;
    int temp = num;
    while(temp){
        ans = ans*10 + (temp%10);
        temp = temp/10;
    }
    return ans;
}

void convertToBinary(int num){
    int binary = 0;
    int temp = num;
    while(temp){
        int digit = temp%2;
        temp = temp/2;
        binary = binary*10 + digit;
    }
    
    binary = reverse(binary);   
    
    printf("%d\n", binary);
}

int main() {
    int nums;
    scanf("%d", &nums);
    int* numbers = (int*)malloc(nums * sizeof(int));
    
    for(int i=0; i<nums; i++){
        scanf("%d", (numbers+i));
    }
    
    // for(int i=0; i<nums; i++){
    //     printf("%d\n", *(numbers+i));
    // }
    
    for(int i=0; i<nums; i++){
        convertToBinary(*(numbers+i));
    }

    return 0;
}