#include <bits/stdc++.h> 

using namespace std;
void rearrangeArray(int arr[], int n)
{
	int temp[n];
	// Write your code here
	for(int i = 0 ; i < n ; i++)
	{
		temp[i] = arr[arr[i]];
	}
	
	for(int i = 0 ; i < n ; i++)
	{
		arr[i] =temp[i];
	}
}

int main(){
    int n = 4;
    int arr[n] = {3,2,0,1};

    rearrangeArray(arr,n);
    for(int i = 0 ; i< n ; i++)
    {
        cout<<arr[i]<<" ";
    }
}