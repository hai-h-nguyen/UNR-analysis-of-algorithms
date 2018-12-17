
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

void Find_Solution_1(int j, int M[], int p[])
{
    if (j == -1)
        return;

    if (M[j] == M[j - 1])
    {
        Find_Solution_1(j-1, M, p);
    }
    else
    {
        Find_Solution_1(p[j] - 1, M, p);
        cout << "x" << j + 1 << " ";
    }
}

void Find_Solution_2(int additionalInfo[], int startIdx)
{
        if (additionalInfo[startIdx] == -1)
        {
            cout << "x" << startIdx + 1 << " ";
            return;
        }

        if (additionalInfo[startIdx] == startIdx - 1)
        {
            Find_Solution_2(additionalInfo, startIdx - 1);
        }

        else
        {
            Find_Solution_2(additionalInfo, additionalInfo[startIdx]);
            cout << "x" << startIdx + 1 << " ";
        }
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

    cout << "Solution way 1: ";
    Find_Solution_1(size - 1, M, p);
    cout << endl;

    cout << "Solution way 2: ";    
    Find_Solution_2(additionalInfo, size - 1);
    cout << endl;

    cout << "Optimal value: " << M[size - 1] << endl;

    return 0; 
} 
