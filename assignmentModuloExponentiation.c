#include<stdio.h>

long long mathModExponentiation(long long base, long long power, long long modNum){
    long long result = 1;
    
    //(a*b) % m = [(a % m) * (b % m)] % m

    while(power>0){
        if(power % 2 == 1){
            result = (result*base) % modNum;
        }
        
        power = power/2;
        base = (base*base) %  modNum;
    }

    return result;
}

int main(){

    long long base, power, modNum;
    printf("enter values for base, power and modNumber: ");
    scanf("%lld %lld %lld", &base, &power, &modNum);

    if(base < 0){
        printf("enter value of base again : ");
        scanf("%lld", &base);
    }else if(power < 0){
        printf("enter value of power again : ");
        scanf("%lld", &power);
    }else if(modNum < 0){
        printf("enter value of modNum again : ");
        scanf("%lld", &modNum);
    }

    long long answer = mathModExponentiation(base, power, modNum);
    printf("Result : %lld", answer);

    return 0;
}
