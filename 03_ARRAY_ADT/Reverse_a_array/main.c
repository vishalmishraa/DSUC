#include <stdio.h>
#include <stdlib.h>

struct Array
{
    int A[20];
    int size;
    int length;
};

void swap(int *x,int *y){
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
}

void display(struct Array arr)
{
    int i;
    printf("Elements are : ");
    for (int i = 0; i < arr.length; i++)
    {
        printf("%d ", arr.A[i]);
    }
};
    //method 1
void Reverse(struct Array *arr){

    int *b;
    int i,j;


    b=(int *)malloc(arr->length*sizeof(int));
    for(i= arr->length-1,j=0;i>=0;i--,j++){
        b[j]=arr->A[i];

    }
    for(i=0;i<arr->length;i++){
        arr->A[i]=b[i];
    }
};

//method 2
void Reverse2(struct Array *arr){
      int i,j;
      for(i=0,j=arr->length-1;i<j;i++,j--){
      swap(&arr->A[i],&arr->A[j]);
      }
}


int main()
{

    struct Array arr = {{2, 3, 4, 5, 6}, 20, 5};

    Reverse2(&arr);
    display(arr);

    return 0;
}