#include <stdio.h>
#include <stdlib.h>

struct Array
{
    int A[20];
    int size;
    int length;
};

void display(struct Array arr)
{
    int i;

    printf("Elements are : ");
    for (int i = 0; i < arr.length; i++)
    {
        printf("%d ", arr.A[i]);
    }
}

void Append(struct Array *arr, int x)
{
    if (arr->length < arr->size)
             arr->A[arr->length++] = x;
    
}

void insert(struct Array *arr,int index,int x){
    if (index>=0 && index<=arr->length)
    {
        for(int i=arr->length;i>index;i--)
                      arr->A[i]=arr->A[i-1];
        arr->A[index] = x;
        arr->length++;
    }
    
}

int main()
{

    struct Array arr = {{2, 3, 4, 5, 6}, 20, 5};

    insert(&arr,2,9);
    Append(&arr, 10);
    display(arr);

    return 0;
}