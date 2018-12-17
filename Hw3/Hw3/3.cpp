#include <stdio.h>

void printArray(int arr[], int size, bool c = false)
{
    int i;
    for (i=0; i < size; i++)
    {
        if (c)
            printf("%c ", arr[i]);
        else
            printf("%d ", arr[i]);
    }
    printf("\n");
}

void merge(int arr[], int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
  
    /* create temp arrays */
    int L[n1], R[n2]; 
  
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1+ j]; 
  
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first sub-array 
    j = 0; // Initial index of second sub-array 
    k = l; // Initial index of merged sub-array 
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 
            arr[k] = L[i]; 
            i++; 
        } 
        else
        { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    /* Copy the remaining elements of L[], if there 
       are any */
    while (i < n1) 
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    /* Copy the remaining elements of R[], if there 
       are any */
    while (j < n2) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 

void nonRecursiveMerge (int arr [], int n)
{
    int m = 1;
    int i = 0;
    int minVal = 0;

    while (m < n)
    {
        i = 0;
        while (i < n - m)
        {
            minVal = (i + 2*m -1 < n - 1) ? (i + 2*m - 1) : (n - 1);
            merge(arr, i, i + m - 1, minVal);
            i += 2*m;
        }

        printArray(arr, n, true);

        m *= 2;
    }
}

// Driver program to test above functions
int main()
{
    int arr[] = {'A', 'S', 'O', 'R', 'T', 'I', 'N', 'G', 'E', 'X', 'A', 'M', 'P', 'L', 'E'};
    // int arr[] = {3, 2, 5, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    nonRecursiveMerge(arr, n);
    return 0;
}