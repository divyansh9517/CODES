#include<bits/stdc++.h>

class Solution {
    // Function to find the leaders in the array.
  public:
    vector<int> leaders(vector<int>& arr) {
        // Code here
        
        int n = arr.size();
        int maxR = arr[n-1];
        vector<int> ans;
        ans.push_back(maxR);
        for(int i = n -2 ;i>=0 ;i--)
        {
            if(maxR <= arr[i])
            {
                maxR = arr[i];
                ans.push_back(maxR);
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
