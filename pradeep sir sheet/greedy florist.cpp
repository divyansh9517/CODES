#include<bits/stdc++.h>
using namespace std;

int miniCost(int n , vector<int> price ,int k)
{
    sort(price.rbegin(),price.rend());
    int totalAmount = 0;
    for(int i = 0 ; i < n ; i++)
    {
        totalAmount += (i/k+1)*price[i];
    }
    return totalAmount;
}

int main(){
    vector<int> arr= {1,2,3,4};
    int k = 3;
    int n = arr.size();
    cout<<miniCost(n,arr,k);
}