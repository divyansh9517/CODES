#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 998244353;

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<int> perm(n);
    for (int i = 0; i < n; ++i)
        cin >> perm[i];

    vector<int> pos;
    int threshold = n - k + 1;
    int maxPartitionValue = 0;

    for (int i = 0; i < n; ++i) {
        if (perm[i] >= threshold) {
            pos.push_back(i);
            maxPartitionValue += perm[i];
        }
    }

    int ways = 1;
    for (int i = 1; i < pos.size(); ++i) {
        ways = (ways * (pos[i] - pos[i - 1])) % MOD;
    }

    cout << maxPartitionValue << " " << ways << "\n";
    return 0;
}
