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

void swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
//append and insertion
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
//==========================================================
//sorting in array
void InsertSort(struct Array *arr, int x)
{
    int i = arr->length - 1;
    if (arr->length == arr->size)
    {
        return;
    }
    while (i >= 0 && arr->A[i] > x)
    {
        arr->A[i + 1] = arr->A[i];
        i--;
    }
    arr->A[i + 1] = x;
    arr->length++;
}

int isSorted(struct Array arr)
{
    int i;
    for (int i = 0; i < arr.length - 1; i++)
    {
        if (arr.A[i] > arr.A[i + 1])
        {
            return 0;
        }
    }
    return 1;
}

void ReArrange(struct Array *arr)
{
    int i, j;
    i = 0;
    j = arr->length - 1;

    while (i < j)
    {
        while (arr->A[i] < 0)
            i++;
        while (arr->A[j] >= 0)
            j--;
        if (i < j)
        {
            swap(&arr->A[i], &arr->A[j]);
        };
    }
}

////Itterative version
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
};

//deletion
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
};

//serching--using loop
int LinearSearch(struct Array arr, int key){
    for (int i = 0; i < arr.length; i++)
    {
        if(key==arr.A[i])
            return i;
    }
    return -1;
}

//improving Linear Search
int LinearSearch(struct Array *arr, int key)
{
    for (int i = 0; i < arr->length; i++)
    {
        if (key == arr->A[i]){
            //1. using tranposition
            // swap(&arr->A[i],&arr->A[i-1]);
            //2. move to head
            swap(&arr->A[i],&arr->A[0]);

            return i;
        }
    }
    return -1;
}

//========================OPERATIONS======================
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
};

//========================================
//reverse
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

    display(arr);

    return 0;
}