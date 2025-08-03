#include<bits/stdc++.h>

using namespace std;
int solve(vector<int> arr)
{
    int largest = INT_MIN;
    int second = INT_MIN;
    for(int i = 0 ; i  < arr.size() ; i++)
    {
        if(largest < arr[i])
        {
            second = largest;
            largest = arr[i];
        }
        else if(arr[i]>second && arr[i] != largest)
        {
            second = arr[i];
        }


    }
    if(second == INT_MIN)
    {
        return -1;
    }
    return second;
}

int main()
{
    vector<int> arr={1,2,3,4,5,6};

    cout<<solve(arr);
}