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

//merging of array
struct Array* Merge(struct Array *arr1, struct Array *arr2)
{
    int i = 0, j = 0, k = 0;
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));

    while (i < arr1->length && j < arr2->length)
    {
        if (arr1->A[i] < arr2->A[j])
        {
            arr3->A[k++] = arr1->A[i++];
        }else{
            arr3->A[k++]=arr2->A[j++];
        }
    }
    for(;i<arr1->length;i++)
         arr3->A[k++]=arr1->A[i];
    for(;j<arr2->length;j++)
         arr3->A[k++]=arr2->A[j];

    arr3->length = arr1->length + arr2->length;
    arr3->size = 10;

    return arr3;
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

    struct Array arr = {{2, 3, 4, 5, 6}, 20, 5};
//merging of array
// struct Array arr1 = {{2, 6, 10,15, 25}, 20, 5};
//     struct Array arr2 = {{5, 4, 7, 18, 20}, 20, 5};

//     struct Array *arr3;

//     isSorted(arr1);
//     // isSorted(arr2);
//     // arr3 = Merge(&arr1,&arr2);


    display(arr);

//     //++++++++++++++++++++++++++++==s



    return 0;
}