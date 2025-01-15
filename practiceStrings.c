#include <stdio.h>
#include <stdlib.h>
#include <string.h>



void eliminateDuplicates(char *str)
{
    int freq[128] = {0};
    for (int i = 0; i < strlen(str); i++)
    {
        freq[str[i]]++;
    }
    for (int i = 0; i < strlen(str); i++)
    {
        if (freq[str[i]] > 0)
        {
            printf("%c", str[i]);
            freq[str[i]] = 0;
        }
    }
    printf("\n");
}



int wordsInString(char *str)
{
    int wordCount = 0;
    while (*str != '\0')
    {
        if (*str != ' ')
        {
            while (*str != ' ' && *str != '\0')
            {
                str++;
            }
            wordCount++;
        }
        else
        {
            str++;
        }
    }
    return wordCount;
}



void longestWordInString(char *str)
{
    int wordCount = 0;
    int longest = 0;
    int maxLen = -1;
    for (int i = 0; i < strlen(str); i++)
    {
        int len = 0;
        int index = 0;
        if (*str != ' ')
        {
            index = i;
            while (str[i] != ' ' && str[i] != '\0')
            {
                i++;
                len++;
            }
            if (len >= maxLen)
            {
                longest = index;
                maxLen = len;
            }
        }
    }

    char longestWord[maxLen + 1];
    longestWord[maxLen] = '\0';
    for (int i = 0; i < maxLen; i++)
    {
        longestWord[i] = str[longest++];
    }
    printf("longest word : %s\n", longestWord);
    return;
}



int startIndex(char *str1, char *str2, int offset)
{
    char start = str1[0];
    for (int i = offset; i < strlen(str2); i++)
    {
        if (start == str2[i])
        {
            return i;
        }
    }
    return -1;
}

void isRotation(char *str, char *str2)
{
    if (strlen(str) != strlen(str2))
    {
        printf("not rotation\n");
        return;
    }

    int secIndex = startIndex(str, str2, 0);

    if (secIndex == -1)
    {
        printf("not rotation\n");
        return;
    }

    // for(int i=0; i<strlen(str);){
    //     if(str[i] != str2[secIndex]){
    //         secIndex = startIndex(str, str2, i+1);
    //         i = 0;
    //         if(secIndex == -1){
    //             printf("not rotation\n");
    //             return;
    //         }
    //     }
    //     i++;
    //     secIndex = (secIndex+1) % strlen(str2);
    // }

    int index = 0;
    while (index < strlen(str))
    {
        if (str[index] == str2[secIndex])
        {
            index++;
            secIndex = (secIndex + 1) % strlen(str2);
        }
        else
        {
            secIndex = startIndex(str, str2, secIndex);
            // printf("%d\n", secIndex);
            if (secIndex == -1)
            {
                printf("not rotation\n");
                return;
            }
            index = 0;
        }
    }

    printf("rotation\n");
    return;
}



void reverse(char *string, int st, int end)
{
    while(st<end){
        char temp = string[st];
        string[st] = string[end];
        string[end] = temp;
        st++;end--;
    }
}

void stringCompression(char *str)
{
    int index = 0;
    int place = 0;
    while (str[index] != '\0')
    {
        char ch = str[index];
        int count = 0;
        while (ch == str[index] && index < strlen(str))
        {
            index++;
            count++;
        }
        str[place++] = ch;

        if (count > 0)
        {
            int num = 0;
            int cIdx = place;
            while (count)
            {
                num = count % 10;
                count = count / 10;
                str[place++] = num + '0';
            }
            reverse(str, cIdx, place-1);
        }
    }
    str[place] = '\0';
    printf("compressed : %s\n", str);
}



void removeAdjDuplicates(char* str){
    char* result = (char *)malloc(100 * sizeof(char));
    int index = 0;
    result[index++] = str[0];

    for(int i=1; i<strlen(str); i++){
        if(str[i] != result[index-1]){
            result[index++] = str[i];
        }else{
            result[index-1] = '\0';
            if(index > 0) index--;
        }
    }

    result[index] = '\0';
    printf("%s\n", result);
}





int main()
{

    char *str = (char *)malloc(100 * sizeof(char));
    printf("enter a string : ");
    fgets(str, 100, stdin);
    if (str[strlen(str) - 1] == '\n')
    {
        str[strlen(str) - 1] = '\0';
    }

    // char* str2 = (char*)malloc(100 * sizeof(char));
    // printf("enter a string : ");
    // fgets(str2, 100, stdin);
    // if(str2[strlen(str2)-1] == '\n'){
    //     str2[strlen(str2)-1] = '\0';
    // }

    // eliminateDuplicates(str);

    // int words = wordsInString(str);
    // printf("words : %d", words);

    // longestWordInString(str);

    // isRotation(str, str2);

    // stringCompression(str);

    removeAdjDuplicates(str);

    return 0;
}