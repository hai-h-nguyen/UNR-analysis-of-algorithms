
#include <stdio.h> 
  
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void printArray(int arr[], int n) 
{ 
    for (int i = 0; i < n; i++) 
        printf("%d ", arr[i]); 
    printf("\n");
} 

void rearrange(int arr[], int n) 
{ 
    int negIdx  = 0;
    int zeroIdx = 0;
    int posIdx = n - 1;

    while (zeroIdx <= posIdx) {
        if (arr[zeroIdx] < 0)
        {
            swap(&arr[negIdx], &arr[zeroIdx]); 
            negIdx++; 
            zeroIdx++;

            printf("Negative Pass: ");
            printArray(arr, n);  
        }

        else if (arr[zeroIdx] == 0)
        {
            zeroIdx++;

            printf("Zero Pass:     ");
            printArray(arr, n);    
        }

        else
        {
            swap(&arr[posIdx], &arr[zeroIdx]); 
            posIdx--;

            printf("Positive Pass: ");
            printArray(arr, n);
        }
    }
}

  
int main() 
{ 
    int arr[] = { 4, 3, -2, 0, 2, 9, -1, 10, 0, 5, 23, -4 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    rearrange(arr, n); 
    printf("\nSorted array: ");
    printArray(arr, n); 
    return 0; 
} 
