#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
int n;
vector<long long> arr;
vector<long long> seg;

void build_st(int idx, int low, int high) {
    if (low == high) {
        seg[idx] = arr[low];
        return;
    }
    int mid = (low + high) / 2;
    build_st(2 * idx + 1, low, mid);
    build_st(2 * idx + 2, mid + 1, high);
    seg[idx] = min(seg[2 * idx + 1],seg[2 * idx + 2]);
}

long long query(int idx, int low, int high, int l, int r) {
    if (r < low || high < l) return 0;
    if (l <= low && high <= r) return seg[idx]; 

    int mid = (low + high) / 2;
    long long left = query(2 * idx + 1, low, mid, l, r);
    long long right = query(2 * idx + 2, mid + 1, high, l, r);
    return min(left,right;)
}


// void update(int idx, int low, int high, int i, int new_value) {
//     if (low == high) {
//         arr[i] = new_value;
//         seg[idx] = new_value;
//         return;
//     }

//     int mid = (low + high) / 2;
//     if (i <= mid) {
//         update(2 * idx + 1, low, mid, i, new_value);
//     } else {
//         update(2 * idx + 2, mid + 1, high, i, new_value);
//     }

//     seg[idx] = seg[2 * idx + 1] + seg[2 * idx + 2];
// }


int main() {
    int q;
    cin >> n >> q;
    arr.resize(n);
    seg.resize(4 * n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    build_st(0, 0, n - 1);

    while (q--) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        cout << query(0, 0, n - 1, l, r) << '\n';
    }

    return 0;
}

