#include<bits/stdc++.h>
using namespace std;

void printSub(int i ,vector<int> ds,int s,int sum , vector<int>&arr,int n)
{
    if(i == n)
    {
        if(s == sum)
        {
            for(auto i : ds)
            {
                cout<<i<<" ";
            }
            cout<<endl;
        }
        return ;
    }
    ds.push_back(arr[i]);
    s += arr[i];
    printSub(i+1,ds,s,sum,arr,n);
    
    s -= arr[i];
    ds.pop_back();
    
    printSub(i+1,ds,s,sum,arr,n);
}

int main()
{
    vector<int> arr ={1,2,1};
    vector<int> ds;
    int sum = 2;
    printSub(0,ds,0,sum,arr,arr.size());
}