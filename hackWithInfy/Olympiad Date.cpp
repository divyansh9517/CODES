#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> & arr)
{
    map<int,int> require = {
        {0,3},
        {1,1},
        {2,2},
        {3,1},
        {5,1}
    };

    map<int,int> mapp;
    for(int i = 0 ; i < arr.size() ; i++)
    {
        mapp[arr[i]]++;

        bool canForm = true;
        for(auto[digit,count] : require)
        {
            if(mapp[digit]<count)
            {
                canForm = false;
                break;
            }
        }
        if(canForm)
        {
            return i+1;
        }
    }
    return 0;
}

int main(){
    int t;
    cin>>t;
    while(t--)
    {
        int n ; 
        cin>>n;
        vector<int> arr(n);
        for(int i= 0 ; i < n ;i++)
        {
            cin>>arr[i];
        }

        int ans = solve(arr);
        cout<<ans<<endl;
    }
}