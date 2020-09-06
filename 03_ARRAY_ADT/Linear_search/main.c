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

int LinearSearch(struct Array arr, int key){
    for (int i = 0; i < arr.length; i++)
    {
        if(key==arr.A[i])
            return i;
    }
    return -1;
}

int main(){

struct Array arr= {{2,3,4,5,6},20,5};


printf("%d\n",LinearSearch(arr,16));
display(arr);

    return 0;
}