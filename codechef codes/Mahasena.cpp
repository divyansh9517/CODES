#include <bits/stdc++.h>
using namespace std;

void solve(int arr[],int n)
{
    
}

int main() {
	// your code goes here
	int n;
	cin>>n;
	int arr[n];
	for(int i=0 ; i<n ;i++)
	{
	   cin>>arr[i];
	}
    int evecnt = 0; 
    int oddCnt = 0;
    for(int  i = 0 ; i < n ; i++)
    {
        if(arr[i] % 2 ==0)
        {
            evecnt++;
        }
        else
        {
            oddCnt++;
        }
    }

    if(evecnt > oddCnt)
    {
        cout<<"READY FOR BATTEL"<<endl;
    }
    else
    {
        cout<<"NOT READY"<<endl;
    }
	return 0;

}