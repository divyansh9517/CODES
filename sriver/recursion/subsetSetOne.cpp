#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    void f(int idx,vector<int>&arr,vector<int>&ans,int sum){
      if(idx == arr.size()){
        ans.push_back(sum);
        return ;
      }

      // pick
      f(idx+1, arr,ans,sum+arr[idx]);
      // not pick 
      f(idx+1,arr,ans,sum);
    }
    vector<int> subsetSums(vector<int>& nums) {
        //your code goes here
        vector<int> ans;
        f(0,nums,ans,0);
        return ans;
    }
};

int main(){
    Solution s;
    vector<int> arr = {5,2,1};
    vector<int> ans = s.subsetSums(arr);
    sort(ans.begin(),ans.end());
    for(int a:ans){
        cout<<a <<" ";
    }
    return 0;
}