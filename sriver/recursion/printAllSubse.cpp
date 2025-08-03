#include<bits/stdc++.h>
using namespace std;

void f(int idx , vector<int>& ds,int s , int sum ,vector<int> &arr,int n){
    if(idx == n){
        if(s == sum){
            for(auto  it : ds)cout<<it<<" ";
        }
        cout<<endl;
        return ;
    }
    ds.push_back(arr[idx]);
    s+= arr[idx];
    f(idx+1 , ds,s,sum,arr,n);// pick 

    ds.pop_back();
    s-=arr[idx];
    f(idx+1 , ds,s,sum,arr,n); // not pick

}

int main(){
    vector<int> arr = {1,2,2,3};
    vector<int>ds;
    f(0,ds,0,3,arr,arr.size());
    return 0;
}