#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage,int k) {
        int n = quality.size();
        double mini = 1e9;
        double totQuality = 0;
        vector<pair<double, int>> ratio;

    
        for (int i = 0; i < n; i++) {
            ratio.push_back({double(wage[i]) / quality[i], quality[i]});
        }

        
        sort(ratio.begin(), ratio.end());

        priority_queue<int> workers;

        
        for (int i = 0; i < n; i++) {
            workers.push(ratio[i].second);
            totQuality += ratio[i].second;

    
            if (workers.size() > k) {
                totQuality -= workers.top();
                workers.pop();
            }

        
            if (workers.size() == k) {
                mini = min(mini, totalQuality *  ratio[i].first);
            }
        }
        return mini;
    }
};
int main()
{
    vector<int> quality = {10,20,5};
    vector<int> wage = {70,50,30};
    int k = 2;
    Solution s;
    double ans = s.mincostToHireWorkers(quality,wage,k);
    cout<<ans;
}