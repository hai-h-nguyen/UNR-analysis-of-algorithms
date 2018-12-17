
#include <stdio.h> 
  
void printArray(int arr[], int n) 
{ 
    for (int i = 0; i < n; i++) 
        printf("%d ", arr[i]); 
}

void checkHeap(int arr[], int n) 
{ 
    int parent = 0;
    int left_child = 0;
    int right_child = 0;

    bool isHeap = true;

    for (int i = 0; i < n/2; i++)
    {
        parent = arr[i];
        left_child = arr[2 * i];
        right_child = arr[2 * i + 1];

        if ((parent < left_child) || (parent < right_child))
        {
            isHeap = false;
            break;
        }
    } 

    printArray(arr, n);
    
    if (isHeap)
    {
        printf("YES, heap\n");
    }
    else
    {
        printf("Not a heap\n");
    }

}

  
int main() 
{ 
    int arr1[] = { 16, 14, 10, 8, 7, 9, 3, 2, 4, 1 }; 
    int arr2[] = {10, 3, 9, 7, 2, 11, 5, 1, 6};
    checkHeap(arr1, sizeof(arr1) / sizeof(arr1[0]));
    checkHeap(arr2, sizeof(arr2) / sizeof(arr2[0]));
    return 0; 
} 
