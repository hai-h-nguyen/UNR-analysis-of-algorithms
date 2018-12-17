
#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

void printArray(int arr[], int n) 
{ 
    for (int i = 0; i < n; i++) 
        cout << arr[i] << " "; 

    cout << endl;
}

int main() 
{ 
    int locations[] = {6, 7, 12, 14}; 
    int revenues[] = {5, 6, 5, 1};

    int size = sizeof(locations) / sizeof(locations[0]);

    // Compute p
    int p[size] = {0};

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (locations[j] < locations[i] - 5)
                p[i] = j + 1;
        }
    }

    p[0] = 0;

    printArray(p, size);

    int M[size] = {0};

    for(int j = 0; j < size; j++)
    {
        M[j] = max(revenues[j] + ((p[j] > 0) ? M[p[j] - 1] : 0), M[(j >= 1) ? j-1 : 0]);
    }

    printArray(M, size);

    return 0; 
} 
