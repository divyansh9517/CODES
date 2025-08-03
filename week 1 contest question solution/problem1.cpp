#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int digit(int num) {
        int sum = 0;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }

    int minSwaps(vector<int>& nums) {
        int n = nums.size();

        vector<pair<pair<int, int>, int>> arr;

        for (int i = 0; i < n; i++) {
            arr.push_back({{digit(nums[i]), nums[i]}, i});
        }

        sort(arr.begin(), arr.end());

        vector<bool> visited(n, false);
        int swaps = 0;

        for (int i = 0; i < n; i++) {

            if (visited[i] || arr[i].second == i)
                continue;

            int cycle = 0;
            int j = i;
            while (!visited[j]) 
            {
                visited[j] = true;
                j = arr[j].second;
                cycle++;
            }   
            swaps += (cycle - 1);
        }
        return swaps;
    }
};


// second solution

class Solution {
public:
    int minSwaps(vector<int>& nums) {
        vector<int> arr;

        for (int i = 0; i < nums.size(); ++i) {
            int sum = 0, m = nums[i];
            while (m != 0) {
                sum += m % 10;
                m /= 10;
            }
            arr.push_back(sum);
        }

        int count = 0;
        int n = arr.size();
        
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    count++;
                    swap(arr[j], arr[j + 1]);
                }
            }
        }

        return count;
    }
};
