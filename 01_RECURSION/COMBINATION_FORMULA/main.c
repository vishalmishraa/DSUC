#include "stdio.h"

//func for factorial
int fact(int n){
     if(n==0) return 1;
     return fact(n-1)*n;
}

//simple func for nCr
int nCr(int n,int r){
    int num,den;
    
    num = fact(n);
    den = fact(r)*fact(n-r);

    return num/den;
}

//RECURSIVE FUNC FOR nCr
int nCr2(int n,int r){
    if(n==r || r==0) return 1;
    return nCr2(n-1,r-1)+nCr2(n-1,r);
}

int main(){
    printf("%d\n",nCr2(5,2));
    return 0;
}