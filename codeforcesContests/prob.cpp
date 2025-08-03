#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

ll solve(const vector<int>& p) {
    ll ans = 0;
    int len = 1; // length of current decreasing segment

    for (int i = 1; i < p.size(); ++i) 
    {
        if (p[i] < p[i - 1]) 
        {
            len++;
        } 
        else 
        {
            // Add sum of lengths of all decreasing subarrays in this segment
            ans += 1LL * len * (len + 1) / 2;
            len = 1;
        }
    }
    // Add the last segment
    ans += 1LL * len * (len + 1) / 2;

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> p(n);
        for (int i = 0; i < n; ++i) {
            cin >> p[i];
        }

        cout << solve(p) << '\n';
    }

    return 0;
}
