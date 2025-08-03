#include<bits/stdc++.h>
using namespace std;
void KthLargestSmallest(vector<int> arr,int k,int kt)
{
    int n = arr.size();
    sort(arr.begin(),arr.end());
    
    int ans1 = arr[kt];
    int ans2 = arr[n-k-1];
    cout<<ans1<<endl;
    cout<<ans2<<endl;

}

int main(){
    vector<int> arr(5);
    for(int i = 0 ; i < arr.size() ; i++)
    {
        cin>>arr[i];
    }
    int k_large = 3;
    int k_smal = 1;
    KthLargestSmallest(arr,k_large,k_smal);
    return 0;
}