#include <bits/stdc++.h>
using namespace std;

bool isDerangement(vector<int>& arr) {
    if (arr.empty()) return false;
    
    vector<int> sorted_arr = arr;
    sort(sorted_arr.begin(), sorted_arr.end());
    
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == sorted_arr[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        // First check if the entire array is a derangement
        if (isDerangement(a)) {
            cout << "YES\n";
            cout << n << "\n";
            for (int i = 0; i < n; i++) {
                if (i > 0) cout << " ";
                cout << a[i];
            }
            cout << "\n";
            continue;
        }
        
        bool found = false;
        vector<int> result;
        int maxLen = 0;
        
        // Try all possible subsequences using bitmask
        for (int mask = 1; mask < (1 << n); mask++) {
            vector<int> subsequence;
            
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    subsequence.push_back(a[i]);
                }
            }
            
            if (isDerangement(subsequence)) {
                if (subsequence.size() > maxLen) {
                    found = true;
                    result = subsequence;
                    maxLen = subsequence.size();
                }
            }
        }
        
        if (found) {
            cout << "YES\n";
            cout << result.size() << "\n";
            for (int i = 0; i < result.size(); i++) {
                if (i > 0) cout << " ";
                cout << result[i];
            }
            cout << "\n";
        } else {
            cout << "NO\n";
        }
    }
    
    return 0;
}