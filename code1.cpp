#include <bits/stdc++.h>
using namespace std;

const int MAX_A = 1e6 + 5;

vector<int> D(MAX_A); // D[x] = number of divisors of x

void precompute_divisors() {
    for (int i = 1; i < MAX_A; ++i) {
        for (int j = i; j < MAX_A; j += i) {
            D[j]++;
        }
    }
}

class SegmentTree {
    vector<long long> segSum;
    vector<int> &arr;
    int n;

public:
    SegmentTree(vector<int> &a) : arr(a) {
        n = arr.size();
        segSum.resize(4 * n);
        build(0, 0, n - 1);
    }

    void build(int ind, int l, int r) {
        if (l == r) {
            segSum[ind] = arr[l];
            return;
        }
        int mid = (l + r) / 2;
        build(2 * ind + 1, l, mid);
        build(2 * ind + 2, mid + 1, r);
        segSum[ind] = segSum[2 * ind + 1] + segSum[2 * ind + 2];
    }

    void update(int ind, int l, int r, int ql, int qr) {
        if (l > qr || r < ql) return;
        if (l == r) {
            if (arr[l] > 2) {
                arr[l] = D[arr[l]];
                segSum[ind] = arr[l];
            }
            return;
        }
        if (segSum[ind] == (r - l + 1)) return; // All values are 1 (stable)
        int mid = (l + r) / 2;
        update(2 * ind + 1, l, mid, ql, qr);
        update(2 * ind + 2, mid + 1, r, ql, qr);
        segSum[ind] = segSum[2 * ind + 1] + segSum[2 * ind + 2];
    }

    long long query(int ind, int l, int r, int ql, int qr) {
        if (l > qr || r < ql) return 0;
        if (ql <= l && r <= qr) return segSum[ind];
        int mid = (l + r) / 2;
        return query(2 * ind + 1, l, mid, ql, qr) + query(2 * ind + 2, mid + 1, r, ql, qr);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    precompute_divisors(); 

    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    for (int &x : arr) cin >> x;

    SegmentTree st(arr);

    while (m--) {
        int type, l, r;
        cin >> type >> l >> r;
        l--, r--;

        if (type == 1) {
            st.update(0, 0, n - 1, l, r);
        } else if (type == 2) {
            cout << st.query(0, 0, n - 1, l, r) << '\n';
        }
    }

    return 0;
}
