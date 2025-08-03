#include<iostream>
using namespace std;

bool sorted(int arr[],int size)
{
    int count = 0;

    if(size == 1)
    {
        return true;
    }

    for(int i = 0; i< size-1;i++)
    {
        if(arr[i]<arr[i+1])
        {
            count++;
        }
    }
    if(count == size)
    {
        return true;
    }
    return false;
}
int main()
{
    int arr[]= {1};
    cout<<sorted(arr,1);
    return 0;
}