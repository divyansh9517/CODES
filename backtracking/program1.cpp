#include <bits/stdc++.h>
using namespace std;

void Binary(vector<int>& arr, int n)
{
    if (n < 1)
    {
        for (int bit : arr)
            cout << bit;
        cout << endl;
        return;
    }

    arr[n - 1] = 0;
    Binary(arr, n - 1);
    
    arr[n - 1] = 1;
    Binary(arr, n - 1);
}

void generateBinary(int n)
{
    vector<int> arr(n);
    Binary(arr, n);
}

int main()
{
    int n = 3;
    generateBinary(n);
    return 0;
}
