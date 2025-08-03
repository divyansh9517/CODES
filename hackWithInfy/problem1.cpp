#include<bits/stdc++.h>

using namespace std;

int solve(vector<int>& a,int e ,int n)
{
    vector<int> arr;
    for(int num : a)
    {
        arr.push_back(num);
        arr.push_back(num);
    }

    sort(arr.begin(),arr.end());

    if(e < n)
    {
        for(int i = 0 ; i < n ; i++)
        {
            if(e == a[i])
            {
                return 1;
            }
        }
    }
    int cnt = 0;
    for(int n : arr)
    {
        e -= n;
        cnt++;

        if(e<=0)
        {
            return cnt;
        }

    }
    return -1;
}

int main(){
    vector<int> a= {1,5,2};
    int e = 2;
    int n = 3 ;
    int ans = solve(a,e,n);
    cout<<ans<<"";

}