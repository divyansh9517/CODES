#include<iostream>

using namespace std;

int findmax(int arr[],int size)
{
    if(size ==0)return -1;

    int maxi = arr[0];

    for(int i = 1; i < size ; i++)
    {
        if(maxi < arr[i])
        {
            maxi = arr[i];
        }
    }
    return maxi;
}

int main(){
    int arr[] = {};
    cout<<findmax(arr,0);
    return 0;
}