#include <bits/stdc++.h>
using namespace std;

class SGTree {
    vector<int> seg;
public:
    SGTree(int n) {
        seg.resize(4 * n);
    }

    void build(int idx, int low, int high, const vector<int>& arr) {
        if (low == high) {
            seg[idx] = arr[low];
            return;
        }
        int mid = (low + high) / 2;
        build(2 * idx + 1, low, mid, arr);
        build(2 * idx + 2, mid + 1, high, arr);
        seg[idx] = __gcd(seg[2 * idx + 1], seg[2 * idx + 2]);
    }

    void countBad(int idx, int low, int high, int l, int r, int x, const vector<int>& arr, int& bad) {
        if (r < low || l > high || bad > 1) return;

        if (low == high) {
            if (arr[low] % x != 0) bad++;
            return;
        }

        if (l <= low && high <= r && seg[idx] % x == 0) return;

        int mid = (low + high) / 2;
        countBad(2 * idx + 1, low, mid, l, r, x, arr, bad);
        countBad(2 * idx + 2, mid + 1, high, l, r, x, arr, bad);
    }

    void update(int idx, int low, int high, int i, int nv) {
        if (low == high) {
            seg[idx] = nv;
            return;
        }
        int mid = (low + high) / 2;
        if (i <= mid)
            update(2 * idx + 1, low, mid, i, nv);
        else
            update(2 * idx + 2, mid + 1, high, i, nv);
        seg[idx] = __gcd(seg[2 * idx + 1], seg[2 * idx + 2]);
    }
};

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int &x : arr) cin >> x;

    SGTree sg(n);
    sg.build(0, 0, n - 1, arr);

    int q;
    cin >> q;
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int l, r, x;
            cin >> l >> r >> x;
            l--, r--;

            int bad = 0;
            sg.countBad(0, 0, n - 1, l, r, x, arr, bad);
            cout << (bad <= 1 ? "YES\n" : "NO\n");
        } else if (type == 2) {
            int i, nv;
            cin >> i >> nv;
            i--;
            sg.update(0, 0, n - 1, i, nv);
            arr[i] = nv;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}