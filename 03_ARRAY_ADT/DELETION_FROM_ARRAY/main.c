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

int Delete(struct Array *arr, int index ){
    if(index>=0 && index<arr->length){
    int x = arr->A[index];

    for(int i = index;i<arr->length;i++){
        arr->A[i] = arr->A[i+1];
    }
    arr->length--;
    return x;
    }

    return 0;
    
}

int main(){
// int n,i;
struct Array arr= {{2,3,4,5,6},20,5};

printf("%d\n",Delete(&arr,2 ));
display(arr);

    return 0;
}