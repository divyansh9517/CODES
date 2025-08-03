#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &arr)
{

    int even = 0, odd=0;
    int n = arr.size();
    for(int i = 0 ; i < n ; i++)
    {
        if(i%2 != arr[i]%2)
        {
            if(i%2 ==0)
            {
                even++;
            }
            else{
                odd++;
            }
        }
    }
    if(even == odd)
    {
        return even;
    }
    return -1;
}
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        int n ;
        cin>>n;
        vector<int> arr(n);
        for(int i = 0; i < n ; i++)
        {
            cin>>arr[i];
        }

        cout<<solve(arr)<<endl;
    }
}