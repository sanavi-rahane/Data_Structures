#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define Size 6 

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
    Function Name : Maximum
    Input : Array and Size of Array
    Output : int

    Problem: To Find largest element in array
    Pattern used: Basic Traversal
    Time Complexity: O(n)
    
  -------------------------------------------------------------*/
int Maximum(int Arr[],int iSize)
{
    int Max = 0;
    int i = 0;

    Max = Arr[0];
    for(i = 1; i < iSize; i++)
    {
        if(Arr[i] > Max)
        {
            Max = Arr[i];
        }
    }

    return Max;
}
/*-------------------------------------------------------------
    Function Name : Minimum
    Input : Array and Size of Array
    Output : int
    
    Problem: To Find Smallest element in array
    Pattern used: Basic Traversal
    Time Complexity: O(n)
    
  -------------------------------------------------------------*/
int Minimum(int Arr[],int iSize)
{
    int Min = 0;
    int i = 0;

    Min = Arr[0];
    for(i = 1; i < iSize; i++)
    {
        if(Arr[i] < Min)
        {
            Min = Arr[i];
        }
    }

    return Min;
}
/*-------------------------------------------------------------
    Function Name : SecondLargest
    Input : Array and Size of Array
    Output : int
    
    Problem: To Find Second largest element in array
    Pattern used: Basic Traversal
    Time Complexity: O(n)
    
  -------------------------------------------------------------*/
int SecondLargest(int Arr[],int iSize)
{
    int Largest = 0;
    int SecondLargest = 0;

    Largest = Arr[0];
    SecondLargest = Arr[0];
    for(int i = 1; i < iSize; i++)
    {
        if(Arr[i] > Largest)
        {
            SecondLargest = Largest;
            Largest = Arr[i];
        }
    }

    return SecondLargest;
}
/*-------------------------------------------------------------
    Function Name : SecondSmallest
    Input : Array and Size of Array
    Output : int
    
    Problem: To Find Second Smallest element in array
    Pattern used: Basic Travelsal
    Time Complexity: O(n)
    
  -------------------------------------------------------------*/
int SecondSmallest(int Arr[],int iSize)
{
    int Smallest = 0;
    int SecondSmallest = 0;

    Smallest = Arr[0];
    SecondSmallest = Arr[0];
    for(int i = 1; i < iSize; i++)
    {
        if(Arr[i] > Smallest)
        {
            SecondSmallest = Smallest;
            Smallest = Arr[i];
        }
    }

    return SecondSmallest;
}
/*-------------------------------------------------------------
    Function Name : CheckSorted
    Input : Array
    Output : boolean
    
    Problem: To Check is array is sorted
    Pattern used: Basic Travelsal
    Time Complexity: O(n)
    
  -------------------------------------------------------------*/
bool CheckSorted(int Arr[],int iSize)
{
    bool bflag = true;

    for(int i = 0; i < iSize-1; i++)
    {
        // check incresing order sorting
        if(!(Arr[i] < Arr[i+1]))
        {
            bflag = false;
        }
    }
    return bflag;
}
/*-------------------------------------------------------------
    Function Name : RemoveDuplicate
    Input : Array
        
    Problem: To Remove duplicates from sorted array
    Pattern used: Two Pointer
    Time Complexity: O(n)
    Space Complexity :O(1)
    
  -------------------------------------------------------------*/

//  Index:  0   1   2   3   4
// Value: [1,  1,  2,  2,  3]
//         ^   ^
//         S   F   (Values same, Fast moves)

// Value: [1,  1,  2,  2,  3]
//         ^       ^
//         S       F   (Different! Move S to index 1, write 2 there)

// Value: [1,  2,  2,  2,  3]
//             ^       ^
//             S       F   (Different! Move S to index 2, write 3 there)

// Final Unique Part: [1, 2, 3]

int RemoveDuplicates(int Arr[],int iSize)
{  //    i        j         
   // 1  2  3  2  3

    int i = 0,j = 0;;
    i = 0;         // slow pointer  (tracks the position of unique elements)

    // Edge condition
    if(iSize == 0) return 0;
    if(CheckSorted(Arr,iSize))
    {
        return -1;
    }

    
    for(j = i+1; j < iSize; j++)        // fast pointer
    {
        if(Arr[i] != Arr[j])   // if equal fast move if not equal slow move id write fast vali value
        {
            i++;
            Arr[i] = Arr[j];
        }
    }
   
    for (int k = i + 1; k < 5; k++) {
    Arr[k] = 0; // "Cleaning" the garbage
    }

    //Return the count of unique elements (index + 1)
    return i+1;
}
/*-------------------------------------------------------------
    Function Name : Recerce
    Input : Array and Size of Array
    Output : Array get reverce 1 index will have value of last index
    
    Problem: To Reverce the element in array
    Pattern used: Basic Travelsal
    Time Complexity: O(n)
    
  -------------------------------------------------------------*/
void Reverce(int Arr[],int iSize)
{
    int i = 0, j = 0;
    int temp = 0;
    for(i = 0,j = iSize-1; i < iSize; i++,j--)
    {
        if(i == j || j < i) break;
        temp = Arr[i];
        Arr[i] = Arr[j];
        Arr[j] = temp;
    
    }
}
/*-------------------------------------------------------------
    Function Name : Summation
    Input : Array and Size of Array
    Output : Sum
    
    Problem: To Find Sum of all element in array
    Pattern used: Basic Travelsal
    Time Complexity: O(n)
    
  -------------------------------------------------------------*/
int Summation(int Arr[],int iSize)
{
    int i = 0,iSum = 0;
    for(i = 0; i < iSize; i++)
    {
       iSum = iSum + Arr[i];
    }
    return iSum;
}
/*-------------------------------------------------------------
    Function Name : Count Frequency
    Input : Array and Size of Array
    Output :
    
    Problem: To print the Count of each element in array for Sorted Array
    Pattern used: Two Pointer
    Time Complexity: O(n)
      if array is not sorted first sort then find O(n \log n))
    -------------------------------------------------------------
    Algorithm :
    step 1 : Check array is sorted or not
    Step 2 : set iCount to 1 and slow pointer to 0 and fast pointer to slow+1
    step 3 : j++
    step 4 : check if i == j then Count++ got to step 3
            ohterwise
            printf count with i
            set i to j position as new element found
            set count to 1 again go to setp 3

    step 5 : print last element count then return 
  -------------------------------------------------------------*/
void CountFrequency(int Arr[],int iSize)
{
    int i = 0, j = 0, iCount = 0;

    if(CheckSorted(Arr,iSize) == false)
    {
        printf("Array is not Sorted\n");
        return ;
    }

    iCount = 1;
    for(j = i+1; j < iSize; j++)
    {
        if(Arr[i] != Arr[j])
        {
            printf("%d->%d\n",Arr[i],iCount);
            i = j;
            iCount = 1;
        }
        else
        {
            iCount++;
        }
        
    }
    printf("%d->%d\n",Arr[i],iCount); 
}
// Count Frequency for unSorted Array
// Time Complexity: O(n^2) .Space Complexity: O(n) as extra visited array
// brut force approch using Visited array 

void CountFrequencyUnsorted(int Arr[],int iSize)
{
   int i= 0,j =0, count = 0;

   int Visited[iSize] ;
   for(int k = 0; k < iSize; k++)
    Visited[k] = 0;



   for(i = 0; i < iSize; i++)
   {
        count = 1;
        if(Visited[i] == 1)
        {
            continue;
        }
        else
        Visited[i] = 1;

        for(j = i+1; j < iSize; j++)
        {
            if(Arr[i] == Arr[j])
            {
                Visited[j] = 1;
                count++;
            }
        }
        printf("%d->%d\n",Arr[i],count);
   }
 
}
// not optimised solution if aaray [10 10000,4] it will create array to 0 to 10001 
// memory wastage 
// best for small array 
void CountFrequencybyFrequencyArray(int Arr[],int iSize)
{
    int iMax = Maximum(Arr,iSize);
    int FreqArr[iMax+1];
    for(int k = 0; k < iMax+1; k++)
    FreqArr[k] = 0;

    for(int i = 0 ; i < iSize; i++)
    {
        FreqArr[Arr[i]]++;
    }

    for(int j = 0; j < iMax+1; j++)
    {
        if(FreqArr[j] != 0)
        printf("%d->%d\n",j,FreqArr[j]);
    }
}
/*-------------------------------------------------------------
    Function Name : LinearSearch
    Input : Array and Size of Array ,Number
    
    Problem: Tofind Element is present or not
    Pattern used: Basic Traversal
    Time Complexity: O(n)
    
  -------------------------------------------------------------*/
void LinearSearch(int Arr[],int iSize,int iNo)
{
    int i = 0;
    for(i = 0; i < iSize; i++)
    {
        if(Arr[i] == iNo)
        {
            printf("Element is Found at index %d\n",i);
            return;
        }
        
        
    }
    printf("Element is not Found\n");
   
}
int main()
{
    int iRet = 0;

    // Dynamic Memory Allocation
    int *Arr[] = malloc(sizeof(int) * Size);
    if(Arr == NULL)
    {
        // if malloc fail to allocate memory
        return 1;
    }
    printf("Enter Elements : \n");
    GetElement(Arr,Size);
    Display(Arr,Size);

    printf("Largest Element in Array : %d\n",Maximum(Arr,Size));
    printf("Smallest Element in Array : %d\n",Minimum(Arr,Size));

    // iRet = RemoveDuplicates(Arr,Size);
    // if(iRet == -1)
    // {
    //     printf("Array is not Sorted\n");
    // }
    // Display(Arr,iRet);

    // Reverce(Arr,Size);
    // Display(Arr,Size);
    if(CheckSorted(Arr,Size) == true)
        printf("Sorted\n");
    else
        printf("Unsorted\n");
    
    CountFrequencyUnsorted(Arr,Size);


    // free the memory
    free(Arr);
    
    return 0;
}