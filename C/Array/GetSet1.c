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
    // static Memory Allocation
    
   // int Arr[] = {10,20,30,40,50};
     int Arr[Size];
    printf("Enter Elements : \n");
    GetElement(Arr,Size);
    Display(Arr,Size);
    return 0;
}