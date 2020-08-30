#include "stdio.h"

//using normal one;
int power(int m,int n){
    if(n==0)
         return 1;
    return power(m,n-1)*m;
}

//this will take less number of multiplication to sind the result
int Lpower(int m,int n){
    //if power = 0
    if(n==0)
        return 1;
    //if power is even
    if(n%2 == 0)
        return Lpower(m*m,n/2);
    //if power is odd
    return m * Lpower(m*m,(n-1)/2);
    
}

int main(){
    int r;
    r=Lpower(2,5);
    printf("%d\n",r);
}
