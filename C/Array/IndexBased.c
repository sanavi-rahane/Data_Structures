/*
2. Rotation / Index Manipulation




Move all zeros to end
Move all zeros to end

Move all negatives to one side

Rearrange array alternatively (+ -)

Union of two arrays

Intersection of two arrays

Missing Number Puzzl

Move all zeros to end

Move all negatives to one side

Rearrange array alternatively (+ -)

Union of two arrays

Intersection of two arrays

Important concept:

swapping

two pointers
Important concept:

swapping

two pointers
Concept:

swapping

index control
*/

#include<stdio.h>
#include<stdlib.h>

#define Size 5 

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
    printf("\n");
}
/*-------------------------------------------------------------
    Function Name : LeftRotateByOne
    Input : Array and Size of Array
    Output : void

    Problem: To Shift the array element to left by one position
    Pattern used: Index Rotation
    Time Complexity: O(n)
    Auther : Sanavi Rahane
    
  -------------------------------------------------------------*/
void LeftRotateByOne(int Arr[],int iSize)
{
    int i = 0;
    int temp = Arr[0];
    for(i = 0; i < iSize-1; i++)
    {
       Arr[i] = Arr[i+1];
    }
    Arr[i] = temp;
}
/*-------------------------------------------------------------
    Function Name : RightRotateByOne
    Input : Array and Size of Array
    Output : void

    Problem: To Shift the array element to Right by one position
    Pattern used: Index Rotation
    Time Complexity: O(n)
    Auther : Sanavi Rahane
    
  -------------------------------------------------------------*/
void RightRotateByOne(int Arr[],int iSize)
{
    int i = 0;
    int temp = Arr[iSize-1];
    for(i = iSize-1; i > 0; i--)
    {
       Arr[i] = Arr[i-1];
    }
    Arr[i] = temp;
}
/*-------------------------------------------------------------
    Function Name : RightRotateByK
    Input : Array and Size of Array
    Output : void

    Problem: To Shift the array element to Right by N times
    Pattern used: Index Rotation
    Time Complexity: O(n * K)
    Auther : Sanavi Rahane
    
  -------------------------------------------------------------*/
// Brut Force Approch
// void RightRotateByK(int Arr[],int iSize,int N)
// {
//     int i = 0;
//     for(int k = 0; k < N; k++)
//     {
//         int temp = Arr[iSize-1];
//         for(i = iSize-1; i > 0; i--)
//         {
//              Arr[i] = Arr[i-1];
//         }
//         Arr[i] = temp;
//     }
    
// }
/*-------------------------------------------------------------
    Function Name : LeftRotateByK
    Input : Array and Size of Array
    Output : void

    Problem: To Shift the array element to left by N times
    Pattern used: Index Rotation 
    Time Complexity: O(n * K)
    Auther : Sanavi Rahane
    
  -------------------------------------------------------------*/
// void LeftRotateByK(int Arr[],int iSize,int K)
// {
//     int i = 0;
//     for(int j = 0; j < K; j++)
//     {
//         int temp = Arr[0];
//         for(i = 0; i < iSize-1; i++)
//         {
//              Arr[i] = Arr[i+1];
//         }
//         Arr[i] = temp;
//     }
// }

// Reversal Algorithm Approch
void Reverse(int Arr[],int Start,int End)
{
    while (Start < End)
    {
        int temp = Arr[Start];
        Arr[Start] = Arr[End];
        Arr[Start]= temp;
        Start++;
        End++;
    }
    
}
/*---------------------------------------------------------------
    Function Name : LeftRotateByK
    Input : Array and Size of Array
    Output : void

    Problem: To Shift the array element to left by N times
    Pattern used: Index Rotation by reversal Algorithm
    Time Complexity: O(n)
    Space Complexity: O(1)
   
 --------------------------------------------------------------*/
void LeftRotateByK(int Arr[],int iSize,int N)
{
    N = N % iSize; // Googly handle kar li!

    // 1. Pehle 'N' elements reverse  (0 se N-1)
    Reverse(Arr, 0, N - 1);

    // 2. Baaki bache elements reverse  (N se iSize-1)
    Reverse(Arr, N, iSize - 1);

    // 3. Poore array ko reverse (0 se iSize-1)
    Reverse(Arr, 0, iSize - 1);
}
// helper function

void RightRotateByK(int Arr[],int iSize,int N)
{
    N = N % iSize; //   important to avoid segmentation fault i case of iSize is smaller that N
    Reverse(Arr, 0, iSize - 1);
    Reverse(Arr, 0, N - 1);
    Reverse(Arr, N, iSize - 1);
}
int FindMissing(int Arr[],int iSize)
{
    int ExpectedSum = 0;
    int iSum = 0;
    for(int i = 0; i <= iSize; i++)
    {
        ExpectedSum = ExpectedSum + i;
        // if(i == iSize) break;
        // iSum = iSum + Arr[i];
    }
    printf("Ex0 %d\n",ExpectedSum);
    printf("Sum %d\n",iSum);
    for(int i = 0; i < iSize; i++)
    {
        iSum = iSum + Arr[i];
    }
   
    return (ExpectedSum-iSum);
    
}
int main()
{
    int iRet = 0;
    int *Arr = malloc(sizeof(int) * Size);

    if(Arr == NULL)
    return -1;

    printf("Enter Element :\n");
    GetElement(Arr,Size);
    //Display(Arr,Size);

    // LeftRotateByOne(Arr,Size);
    // Display(Arr,Size);
    // RightRotateByOne(Arr,Size);
    // Display(Arr,Size);
    // LeftRotateByK(Arr,Size,3);
    // Display(Arr,Size);
    // RightRotateByK(Arr,Size,2);
    // Display(Arr,Size);
    iRet = FindMissing(Arr,Size);
    printf("Missing Integer : %d\n",iRet);

    free(Arr);
    return 0;
}