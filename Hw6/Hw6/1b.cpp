
#include <iostream>

using namespace std;

int locations[] = {6, 7, 12, 14}; 
int revenues[] = {5, 6, 5, 1};

void printTable(int arr[], int n, const char name[]) 
{ 
    cout << name << endl;
    for (int i = 0; i < n; i++) 
        cout << arr[i] << " "; 

    cout << endl;
}

int main() 
{ 
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

    // Compute M
    int M[size] = {0};

    int additionalInfo[size] = {0};

    for(int j = 0; j < size; j++)
    {
        int a = revenues[j] + ((p[j] > 0) ? M[p[j] - 1] : 0);
        int b = M[(j >= 1) ? j-1 : 0];


        if (a >= b)
        {
            additionalInfo[j]  = ((p[j] > 0) ? p[j] - 1 : -1);
            M[j] = a;
        }
        else
        {
            additionalInfo[j] = ((j >= 1) ? j-1 : 0);
            M[j] = b;
        }
    }


    printTable(additionalInfo, size, "Additional table:");
    printTable(M, size, "Sub-solution table: ");

    cout << "Optimal value: " << M[size - 1] << endl;

    return 0; 
} 
