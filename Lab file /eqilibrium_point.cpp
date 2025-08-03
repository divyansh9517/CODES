#include<bits/stdc++.h>
using namespace std;


vector<int> prefix(vector<int> &arr)
{
    int n = arr.size();
    vector<int> prefix(n);
    prefix[0] = arr[0];
    
    for(int i = 1 ; i < arr.size(); i++)
    {
        prefix[i] = prefix[i-1] + arr[i];
    }
    return prefix;
}

vector<int> suffix(vector<int> &arr)
{
    int n = arr.size();
    int sum = 0;
    vector<int> suffix(n);
    suffix[n-1] = arr[n-1];
    for(int i = arr.size()-2; i>= 0 ; i--)
    {
        suffix[i] = suffix[i+1] +arr[i];
    }
    return suffix;
}
int equilibrium(vector<int> &arr)
{
    vector<int> pref = prefix(arr);
    vector<int> suff = suffix(arr);

    for(int i = 0; i < arr.size() ; i++)
    {
        if(pref[i] == suff[i])
        {
            return i;   
        }
    }
    return -1;
}
int main()
{
    vector<int> arr = {1,2,3,0,6};
    int ans = equilibrium(arr);
    cout<<ans;
}