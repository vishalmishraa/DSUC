#include <stdio.h>
#include <stdlib.h>

struct  Array
{
    int *A;
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

int main(){
int n,i;
struct Array arr;
printf("Ennter sze of an Array :");
scanf("%d",&arr.size);
arr.A=(int *)malloc(arr.size*sizeof(int));  
arr.length = 0;


printf("\nEnter how many numbers :");
scanf("%d",&n);


printf("Enter all elements :");
for (int i = 0; i < n; i++)
{
    scanf("%d",&arr.A[i]);
}
arr.length=n;
display(arr);

    return 0;
}