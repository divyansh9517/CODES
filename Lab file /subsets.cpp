#include <bits/stdc++.h>
using namespace std;

void solve(int idx, vector<int>& arr, vector<vector<int>>& ans, vector<int>& op) {
    if(idx == arr.size()) {
        ans.push_back(op);
        return;
    }

    // Exclude current element
    solve(idx + 1, arr, ans, op);

    // Include current element
    op.push_back(arr[idx]);
    solve(idx + 1, arr, ans, op);

    // Backtrack
    op.pop_back();
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    vector<vector<int>> ans;
    vector<int> op;
    int idx = 0;

    solve(idx, arr, ans, op);

    for(int i = 0; i < ans.size(); i++) {
        for(int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
