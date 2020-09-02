#include "stdio.h"
#include "stdlib.h"

int main(){
    //method 1: create array in stack
    int A[3][4]= {
        {1,2,3,4},
        {2,4,6,8},
        {1,3,5,7}
    };

    //PRINTING ARRAYS   
    int i,j;
    printf("\nmethdo 1: \n");
    for ( i = 0; i < 3; i++)
    {
        for ( j = 0; j < 4; j++)
        {
            printf("%d ",A[i][j]);
        }
        printf("\n");
    }

    //method 2: 
    //rows create in stack
    int *B[4];
    //array's created in heap
    B[0]=(int *)malloc(4*sizeof(int));
    B[1]=(int *)malloc(4*sizeof(int));
    B[2]=(int *)malloc(4*sizeof(int));

    printf("\nmethdo 2: \n");
    for ( i = 0; i < 3; i++)
    {
        for ( j = 0; j < 4; j++)
        {
            printf("%d ",B[i][j]);
        }
        printf("\n");
    }

    //method 3:
    //usig double pointer: rows and stack both created in heap
    int **C;
    C=(int **)malloc(4*sizeof(int *));
    //creating array in heap
    C[0]=(int *)malloc(4*sizeof(int *));
    C[1]=(int *)malloc(4*sizeof(int *));
    C[2]=(int *)malloc(4*sizeof(int *));
    
    printf("\nmethdo 3: \n");
    for ( i = 0; i < 3; i++)
    {
        for ( j = 0; j < 4; j++)
        {
            printf("%d ",C[i][j]);
        }
        printf("\n");
    }
    




    return 0;
}