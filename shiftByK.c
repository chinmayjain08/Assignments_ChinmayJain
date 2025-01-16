#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// void shiftByK(char* str, int k){
//     int len = strlen(str);
//     char ans[len];
//     for(int i=0; i<len; i++){
//         ans[(i+k)%len] = str[i];
//     }
//     printf("%s\n", ans);
// }

void shiftByK(char* str, int k){
    int len = strlen(str);
    for(int i=0; i<k; i++){
        char temp = str[len-1];
        for(int j=len-1; j>0; j--){
            str[j] = str[j-1];
        }
        str[0] = temp;
    }
    printf("%s\n", str);
}

int main() {
    
    char* str = (char*)malloc(1001 * sizeof(char));
    fgets(str, 1001, stdin);
    str[strcspn(str, "\n")] = '\0';
    
    int k;
    scanf("rotate count (k) : ");
    scanf("%d", &k);
    
    shiftByK(str, k);

    return 0;
}