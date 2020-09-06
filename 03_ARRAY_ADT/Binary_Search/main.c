#include <stdio.h>
#include <stdlib.h>

struct  Array
{
    int A[20];
    int size;
    int length;
};

void display(struct Array arr){
int i;
printf("Elements are : ");
for (int i = 0; i < arr.length; i++)
{
    printf("%d ",arr.A[i]);
}
}

//Itterative version
int BinarySearch(struct Array arr,int key){
    int l,mid,h;
    l=0;
    h=arr.length-1;
    
    while (l<=h)
    {
        mid=(l+h)/2;
        if (key==arr.A[mid])
        {
            return mid;
        }else if (key<arr.A[mid])
        {
            h=mid-1;
        }else if (key>arr.A[mid])
        {
            l=mid+1;
        }
    }
    return -1;
};

int RBinarySearch(int a[],int l,int h,int key){
    int mid;

    if(l<=h){
        mid=(l+h)/2;
        if (key==a[mid])
        {
            return mid;
        }else if(key<a[mid]){
            return RBinarySearch(a,l,mid-1,key);
        }else if(key>a[mid]){
            return RBinarySearch(a,mid+1,h,key);
        }
        
    } 



    return -1;
}


int main(){

struct Array arr= {{2,3,4,5,6},20,5};


printf("%d\n",RBinarySearch(arr.A,0,arr.length,4));
display(arr);

    return 0;
}