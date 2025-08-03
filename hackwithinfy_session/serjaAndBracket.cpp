#include <bits/stdc++.h>
using namespace std;

class info {
public:
    int open, close, full;
    info(int _open, int _close, int _full) {
        open = _open;
        close = _close;
        full = _full;
    }

    info() {
        open = 0;
        close = 0;
        full = 0;
    }
};

info merge(info left, info right) {
    info ans;
    int matched = min(left.open, right.close);
    ans.full = left.full + right.full + matched;
    ans.open = left.open + right.open - matched;
    ans.close = left.close + right.close - matched;
    return ans;
}

void build(int ind, int low, int high, string &s, vector<info> &seg) {
    if (low == high) {
        seg[ind].open = (s[low] == '(');
        seg[ind].close = (s[low] == ')');
        seg[ind].full = 0;
        return;
    }

    int mid = (low + high) / 2;
    build(2 * ind + 1, low, mid, s, seg);
    build(2 * ind + 2, mid + 1, high, s, seg);
    seg[ind] = merge(seg[2 * ind + 1], seg[2 * ind + 2]);
}

info query(int ind, int low, int high, int l, int r, vector<info> &seg) {
    if (r < low || high < l) {
        return info();  // Empty node
    }

    if (l <= low && high <= r) {
        return seg[ind];
    }

    int mid = (low + high) / 2;
    info left = query(2 * ind + 1, low, mid, l, r, seg);
    info right = query(2 * ind + 2, mid + 1, high, l, r, seg);
    return merge(left, right);
}

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    if (n == 0) return;

    vector<info> seg(4 * n);  // Heap allocation
    build(0, 0, n - 1, s, seg);
    
    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        l--, r--; // 0-based indexing

        // Validation
        if (l > r || l < 0 || r >= n) {
            cout << "0\n";
            continue;
        }

        info ans = query(0, 0, n - 1, l, r, seg);
        cout << ans.full * 2 << '\n'; // each matched pair has length 2
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
