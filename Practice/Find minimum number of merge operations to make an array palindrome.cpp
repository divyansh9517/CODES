#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &arr)
{
    int ans = 0 ;
    int i = 0  ;
    int j = arr.size()-1;
    while(i<= j)
    {
        if(arr[i] == arr[j])
        {
            i++;
            j--;
        }

        else if(arr[i]>arr[j])
        {
            j--;
            arr[j]+=arr[j+1];
            ans++;
        }
        else{
            i++;
            arr[i]+=arr[i-1];
            ans++;
        }
    }
    return ans;

}
int main()
{
    vector<int> arr {1,2,9,3,1};
    cout<<solve(arr);
}