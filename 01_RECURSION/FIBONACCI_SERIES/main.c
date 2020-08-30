#include "stdio.h"


//using iterative
int fib(int n){
    int t0=0,t1=1,i,s=0;

    if(n<=1) return n;
    for(i=2;i<=n;i++){
        s=t0+t1;
        t0=t1;
        t1=s;
    };
    return s;
}

//using recursive func.
int rfib(int n){
    if(n<=1) return n;
    return rfib(n-2)+rfib(n-1);
}

//MEMOIZATION FUNC FOR FIBONACCI SERIES
int f[10];
int mfib(int n){
    if(n<=1){
        f[n]=n;
        return n;
    }else{
        if(f[n-2]==-1)
            f[n-2]=mfib(n-2);
        if(f[n-1]==-1)
            f[n-1]=mfib(n-1);
        f[n]=f[n-2]+f[n-1];
        return f[n-2]+f[n-1];
    }
}

int main(){
    //first itialise the meomization func array
    int i;
    for(i=0;i<10;i++)
          f[i] = -1;
    printf("%d\n",mfib(6));

    return 0;
}