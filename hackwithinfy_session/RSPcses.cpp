#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
int n, q;
vector<long long> arr(MAXN);
vector<long long> seg(4 * MAXN);

// Build segment tree
void build(int idx, int low, int high) {
    if (low == high) {
        seg[idx] = arr[low];
        return;
    }
    int mid = (low + high) / 2;
    build(2 * idx + 1, low, mid);
    build(2 * idx + 2, mid + 1, high);
    seg[idx] = seg[2 * idx + 1] + seg[2 * idx + 2];
}

// Query sum in range [l, r]
long long query(int idx, int low, int high, int l, int r) {
    if (r < low || high < l) return 0; // No overlap
    if (l <= low && high <= r) return seg[idx]; // Total overlap

    int mid = (low + high) / 2;
    long long left = query(2 * idx + 1, low, mid, l, r);
    long long right = query(2 * idx + 2, mid + 1, high, l, r);
    return left + right;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    build(0, 0, n - 1);

    while (q--) {
        int a, b;
        cin >> a >> b;
        a--, b--; // Convert to 0-based indexing
        cout << query(0, 0, n - 1, a, b) << '\n';
    }

    return 0;
}
