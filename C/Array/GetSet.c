#include<stdio.h>
#include<stdlib.h>
#define Size 10 
void GetElement(int Arr[],int iSize)
{
    int i = 0;
    for(i = 0; i < iSize; i++)
    {
        scanf("%d",&Arr[i]);
    }
}
void Display(int Arr[],int iSize)
{
    int i = 0;
    for(i = 0; i < iSize; i++)
    {
        printf("%d\t",Arr[i]);
    }
}
int main()
{
    // Dynamic Memory Allocation
    int *Arr = malloc(sizeof(int));
    if(Arr == NULL)
    {
        // if malloc fail to allocate memory
        return 1;
    }
    printf("Enter Elements : \n");
    GetElement(Arr,Size);
    Display(Arr,Size);
    // free the memory
    free(Arr);
    
    return 0;
}