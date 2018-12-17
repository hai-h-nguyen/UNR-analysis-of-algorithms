#include <stdio.h>

int numComp = 0;
 
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%c ", arr[i]);
}

void bubbleSort(int arr[], int n)
{
   int i, j;
   int leftStartIdx = 1;
   int rightStartIdx = n; 

   while (leftStartIdx < rightStartIdx)
   {
       // Left2Right pass
         for (j = leftStartIdx; j <= rightStartIdx - 1; j++)
         {
            numComp++;

            if (arr[j-1] > arr[j])
            {
               swap(&arr[j], &arr[j-1]);
            }
         }
        

        rightStartIdx  -= 1;


        printf("Left2Right pass: ");
        printArray(arr, n);
        printf("\n");        

        if (leftStartIdx >= rightStartIdx)
        	break;

        // Right2Left pass
         for (j = rightStartIdx - 1; j >= leftStartIdx; j--)
         {
            numComp++;

            if (arr[j - 1] > arr[j])
            {
               swap(&arr[j - 1], &arr[j]);

            }
         }
         
         printf("Right2Left pass: ");
         printArray(arr, n);
         printf("\n");

         if (leftStartIdx >= rightStartIdx)
    		  break;

    	leftStartIdx += 1;
   }
}
 
int main()
{
    int arr[] = {'E', 'A', 'S', 'Y', 'Q', 'U', 'E', 'S', 'T', 'I', 'O', 'N'};
    int n = sizeof(arr)/sizeof(arr[0]);
    bubbleSort(arr, n);
    printf("%d", numComp);
    return 0;
}
