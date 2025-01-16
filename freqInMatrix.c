// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>
int main(){
    
    int n, m;
    scanf("%d", &n);
    scanf("%d", &m);
    int** nums = (int**)malloc(n * sizeof(int*));
    for(int i=0; i<n; i++){
        nums[i] = (int*)malloc(m * sizeof(int));
    }
    int freq[101] = {0};
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf("%d", (*(nums+i)+j));
            if(*(*(nums + i) + j) < 1 || *(*(nums + i) + j) > 100){
                j--;
                printf("enter number again");
                continue;
            }
            freq[*(*(nums+i)+j)]++;
        }
    }
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(freq[*(*(nums+i)+j)] == -1) continue;
            printf("%d->%d times ", *(*(nums+i)+j), freq[*(*(nums+i)+j)]);
            freq[*(*(nums+i)+j)] = -1;
        }
        printf("\n");
    }
    
    return 0;
}