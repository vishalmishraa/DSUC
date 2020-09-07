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

int get(struct Array arr,int index){
    if(index>=0 && index<arr.length)
            return arr.A[index];

    return -1;
}

void set(struct Array *arr,int index, int x){
    if(index>=0 && index<arr->length)
             arr->A[index]=x;
};

int max(struct Array arr){
    int max = arr.A[0];
    int i;
    for(i=0;i<arr.length;i++){
        if(arr.A[i]>max)
            max=arr.A[i];
    }
    return max;
};

int min(struct Array arr){
    int min = arr.A[0];
    int i;
    for(i=0;i<arr.length;i++){
        if(arr.A[i]<min)
            min=arr.A[i];
    }
    return min;
};

int sum(struct Array arr){
    int s = 0;
    int i;
    for(i=0;i<arr.length;i++)
          s+=arr.A[i];

    return s;
};

float avg(struct Array arr){
    return (float)sum(arr)/arr.length;
}

int main()
{

    struct Array arr = {{2, 3, 4, 5, 6}, 20, 5};
    

    printf("\nget: %d\n",get(arr,1));
    set(&arr,2,8);
    printf("\nsum: %d\n",sum(arr));
    printf("\nmax: %d\n",max(arr));
    printf("\nmin: %d\n",min(arr));
    printf("\navg: %f\n",avg(arr));

    display(arr);

    return 0;
}