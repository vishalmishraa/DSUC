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
};

//function for union
struct Array* Union(struct Array *arr1, struct Array *arr2)
{
    int i = 0, j = 0, k = 0;
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));

    while (i < arr1->length && j < arr2->length)
    {
        //if array 1 element is smaller
        if (arr1->A[i] < arr2->A[j])
        {
            arr3->A[k++] = arr1->A[i++];
        //if array 2 element is smaller
        }else if (arr2->A[j] < arr1->A[i]){
            arr3->A[k++]=arr2->A[j++];
        }else{
            //if both are equale then take any one and increment bot I and J
            arr3->A[k++]=arr1->A[i++];
            j++;
        }
    }
    for(;i<arr1->length;i++)
         arr3->A[k++]=arr1->A[i];
    for(;j<arr2->length;j++)
         arr3->A[k++]=arr2->A[j];

    arr3->length = k;
    arr3->size = 10;

    return arr3;
};

//function for Intersection
struct Array* Intersection(struct Array *arr1, struct Array *arr2)
{
    int i = 0, j = 0, k = 0;
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));


    //copy element only if they are equal
    while (i < arr1->length && j < arr2->length)
    {
        //if array 1 element is smaller
        if (arr1->A[i] < arr2->A[j])
        {
            i++;
        //if array 2 element is smaller
        }else if (arr2->A[j] < arr1->A[i]){
            j++;
        }else if(arr1->A[i]==arr2->A[j]){
            //if both are equale then take any one and increment bot I and J
            arr3->A[k++]=arr1->A[i++];
            j++;
        }
    }

    arr3->length = k;
    arr3->size = 10;

    return arr3;
};

//function for difference
struct Array* Difference(struct Array *arr1, struct Array *arr2)
{
    int i = 0, j = 0, k = 0;
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));


    //copy element only from first array
    while (i < arr1->length && j < arr2->length)
    {
        //if array 1 element is smaller
        if (arr1->A[i] < arr2->A[j])
        {
            arr3->A[k++] = arr1->A[i++];
        //if array 2 element is smaller
        }else if (arr2->A[j] < arr1->A[i]){
         j++;
        }else{
            //if both are equale then take any one and increment bot I and J
            i++;
            j++;
        }
    }
    //if remaning only copy from arr1;
    for(;i<arr1->length;i++)
         arr3->A[k++]=arr1->A[i];


    arr3->length = k;
    arr3->size = 10;

    return arr3;
};

int main()
{

    struct Array arr1 = {{2, 6, 10,15, 25}, 20, 5};
    struct Array arr2 = {{3, 6, 7, 15, 20}, 20, 5};
    struct Array *arr3;

    arr3 = Difference(&arr1,&arr2);
    display(*arr3);

    return 0;
}