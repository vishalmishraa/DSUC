#include "stdio.h"

//n = number of disk
//a = from 
//b = intermediate/using
//c = destination
static int i=1;
int TOH(int n,int a,int b,int c){
    if(n>0){
        TOH(n-1,a,c,b);
        printf("\nstep %d :(%d to %d)\n",i++,a,c);
        TOH(n-1,b,a,c);
    }
};

int main(){
    TOH(30,1,2,3);
    return 0;
}