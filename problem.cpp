#include <bits/stdc++.h>
using namespace std;

class SegmentTree {
    vector<long long> seg;
    vector<int> &arr;
    vector<int> &divisors;
    int n;

public:
    SegmentTree(int size, vector<int>& a, vector<int>& d) : arr(a), divisors(d) {
        n = size;
        seg.resize(4 * n);
        build(0, 0, n - 1);
    }

    void build(int ind, int low, int high) {
        if (low == high) {
            seg[ind] = arr[low];
            return;
        }
        int mid = (low + high) / 2;
        build(2 * ind + 1, low, mid);
        build(2 * ind + 2, mid + 1, high);
        seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
    }

    void update(int ind, int low, int high, int l, int r) {
        
        if (low > r || high < l || seg[ind] == (high - low + 1)) return;

        if (low == high) {
            arr[low] = divisors[arr[low]];
            seg[ind] = arr[low];
            return;
        }

        int mid = (low + high) / 2;
        update(2 * ind + 1, low, mid, l, r);
        update(2 * ind + 2, mid + 1, high, l, r);
        seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
    }

    long long query(int ind, int low, int high, int l, int r) {
        if (low > r || high < l) return 0;
        if (low >= l && high <= r) return seg[ind];
        int mid = (low + high) / 2;
        return query(2 * ind + 1, low, mid, l, r) +
               query(2 * ind + 2, mid + 1, high, l, r);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    vector<int> arr(n);
    for (int &x : arr) cin >> x;
    vector<int> divisors(1e6 + 1, 1);
    for (int i = 2; i <= 1e6; ++i) {
        for (int j = i; j <= 1e6; j += i) {
            divisors[j]++;
        }
    }

    SegmentTree st(n, arr, divisors);

    while (q--) {
        int type, l, r;
        cin >> type >> l >> r;
        --l; --r;

        if (type == 1) {
            cout << st.query(0, 0, n - 1, l, r) << '\n';
        } else if (type == 2) {
            st.update(0, 0, n - 1, l, r);
        }
    }

    return 0;
}
