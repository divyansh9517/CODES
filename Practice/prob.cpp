#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool checkEqualPartitions(vector<int>& nums, long long target) {
        int n = nums.size();
        int total = (1 << n); // total possible subsets

        for (int mask = 1; mask < total - 1; ++mask) {
            long long prod1 = 1;
            vector<int> remaining;
            bool overflow = false;

            for (int i = 0; i < n; ++i) {
                if (mask & (1 << i)) {
                    if (__builtin_mul_overflow(prod1, (long long)nums[i], &prod1)) {
                        overflow = true;
                        break;
                    }
                } else {
                    remaining.push_back(nums[i]);
                }
            }

            if (overflow || prod1 != target) continue;

            long long prod2 = 1;
            for (int x : remaining) {
                if (__builtin_mul_overflow(prod2, (long long)x, &prod2)) {
                    prod2 = -1;
                    break;
                }
            }

            if (prod2 == target) return true;
        }

        return false;
    }

    bool check(vector<int>& nums,long long target)
    {
        int n = nums.size();
        int total = (1 << n); // Total subsets

        for (int mask = 1; mask < total - 1; ++mask) {
            long long prod1 = 1;
            long long prod2 = 1;

            for (int i = 0; i < n; ++i) {
                if (mask & (1 << i)) {
                    prod1 *= nums[i];
                } else {
                    prod2 *= nums[i];
                }
            }

            if (prod1 == target && prod2 == target)
                return true;
        }
        return false;
    }
};
int main(){
    Solution s;
    vector<int> arr = {25,20,2,10,16};
    int target = 400;
    bool ans = s.check(arr,target);

    if(ans)
    {
        cout<<"Yes";
    }
    else
    {
        cout<<"NO";
    }
}