#include <bits/stdc++.h>
using namespace std;

int main() {
    int tc;
    cin >> tc;  // Number of test cases

    while(tc--) {
        int n;
        cin >> n;
        vector<long long> a(n);
        
        for(auto &x : a) cin >> x;  // Input array

        sort(a.begin(), a.end());  // Sort the array

        // If the sum of first and last is even, no need to remove anything
        if((a[0] + a[n-1]) % 2 == 0) {
            cout << 0 << "\n";
            continue;
        }

        // Otherwise, find first position where parity changes from a[0]
        int first_flip = -1, last_flip = -1;
        for(int i = 0; i < n; i++) {
            if(first_flip == -1 && (a[i] % 2 != a[0] % 2)) {
                first_flip = i;
            }
            if(a[i] % 2 != a[n-1] % 2) {
                last_flip = i;
            }
        }

        // Output minimum of the two: how many to remove from start or end
        cout << min(first_flip, n - last_flip - 1) << "\n";
    }

    return 0;
}
