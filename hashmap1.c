#include <stdio.h>
#include <string.h>

typedef struct alpha{
    int firstIndex;
    int count;
}alpha;

alpha alphabets[128];

int search(char key){
    if(alphabets[key].count != 0){
        return key;
    }
    return -1;
}

int main() {
    
    char word[25];
    scanf("%s", word);
    
    for(int i=0; i<128; i++){
        alphabets[i].firstIndex = -1;
        alphabets[i].count = 0;
    }
    
    for(int i=0; i<strlen(word); i++){
        if(search(word[i]) == -1){
            alphabets[word[i]].firstIndex = i;
        }
        alphabets[word[i]].count++;
    }
    
    for(int i=0; i<strlen(word); i++){
        if(alphabets[word[i]].firstIndex != -1){
            printf("char: %c firstindex: %d count: %d\n", word[i], alphabets[word[i]].firstIndex, alphabets[word[i]].count);
            alphabets[word[i]].firstIndex = -1;
        }
    }

    return 0;
}