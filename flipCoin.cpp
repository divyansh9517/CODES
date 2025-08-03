#include <bits/stdc++.h>
using namespace std;

class ST {
    vector<int> seg, lazy;
public:
    ST(int n) {
        seg.resize(4 * n);
        lazy.resize(4 * n);
    }

    void build(int ind, int low, int high, vector<int> &arr) {
        if (low == high) {
            seg[ind] = arr[low];
            return;
        }
        int mid = (low + high) >> 1;
        build(2 * ind + 1, low, mid, arr);
        build(2 * ind + 2, mid + 1, high, arr);
        seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
    }

    void push(int ind, int low, int high) {
        if (lazy[ind] % 2 != 0) { // odd means flip
            seg[ind] = (high - low + 1) - seg[ind];
            if (low != high) {
                lazy[2 * ind + 1] ^= 1;
                lazy[2 * ind + 2] ^= 1;
            }
        }
        lazy[ind] = 0;
    }

    void update(int ind, int low, int high, int l, int r) {
        push(ind, low, high);

        if (high < l || r < low)
            return;

        if (low >= l && high <= r) {
            lazy[ind] ^= 1;
            push(ind, low, high);
            return;
        }

        int mid = (low + high) >> 1;
        update(2 * ind + 1, low, mid, l, r);
        update(2 * ind + 2, mid + 1, high, l, r);
        seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
    }

    int query(int ind, int low, int high, int l, int r) {
        push(ind, low, high);

        if (high < l || r < low)
            return 0;

        if (low >= l && high <= r)
            return seg[ind];

        int mid = (low + high) >> 1;
        int left = query(2 * ind + 1, low, mid, l, r);
        int right = query(2 * ind + 2, mid + 1, high, l, r);
        return left + right;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    ST st(n);
    st.build(0, 0, n - 1, arr);

    int q;
    cin >> q;
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int l, r;
            cin >> l >> r;
            if (l < 0 || r >= n || l > r) {
                cout << "Invalid query range\n";
                continue;
            }
            cout << st.query(0, 0, n - 1, l, r) << endl;
        } else if (type == 2) {
            int l, r;
            cin >> l >> r;
            if (l < 0 || r >= n || l > r) {
                cout << "Invalid update range\n";
                continue;
            }
            st.update(0, 0, n - 1, l, r);
        } else {
            cout << "Invalid operation type\n";
        }
    }

    return 0;
}
