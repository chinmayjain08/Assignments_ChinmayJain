#include<stdio.h>

long long mathModExponentiation(long long b, long long n, long long m){
    long long result = 1;
    
    //(a*b) % m = [(a % m) * (b % m)] % m

    while(n>0){
        if(n % 2 == 1){
            result = (result*b) % m;
        }
        
        n = n/2;
        b = (b*b) %  m;
    }

    return result;
}

int main(){

    long long b, n, m;
    printf("enter values for b, n and m: ");
    scanf("%lld %lld %lld", &b, &n, &m);

    long long answer = mathModExponentiation(b, n, m);
    printf("Result : %lld", answer);

    return 0;
}