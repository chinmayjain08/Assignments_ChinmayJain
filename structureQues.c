#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
    char* item_name;
    int item_price;
}Item;

int main(){

    int n;
    scanf("%d", &n);
    Item* items = (Item*)malloc(n * sizeof(Item));
    for(int i=0; i<n; i++){
        (*(items+i)).item_name = (char*)malloc(100 * sizeof(char));
    }
    
    for(int i=0; i<n; i++){
        printf("enter item%d name and price: ", i+1);
        scanf("%s %d", (*(items+i)).item_name, &(*(items+i)).item_price);
    }

    // for(int i=0; i<n; i++){
    //     printf("itemname : %s\nprice: %d\n\n", (*(items+i)).item_name, (*(items+i)).item_price);
    // }
    
    printf("item details: \n");
    for(int i=0; i<n; i++){
        char* curr = items[i].item_name;
        int count = 1;
        for(int j=i+1; j<n; j++){
            if(strcmp(items[j].item_name, curr) == 0 && items[j].item_price >= 0){
                count++;
                items[j].item_price *= -1;
            }
        }
        if(items[i].item_price >= 0)
        printf("itemname : %s\nprice: %d\nquantity: %d\n\n", (*(items+i)).item_name, (*(items+i)).item_price, count);
    }
    
    

    return 0;
}