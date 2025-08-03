#include <bits/stdc++.h>
using namespace std;

class SGTree {
    vector<int> seg;
public:
    SGTree(int n) 
    {
        seg.resize(4 * n + 1);
    }

    void build(int idx, int low, int high, int arr[]) 
    {
        if (low == high) 
        {
            seg[idx] = arr[low];
            return;
        }
        int mid = (low + high) / 2;
        build(2 * idx + 1, low, mid, arr);
        build(2 * idx + 2, mid + 1, high, arr);
        seg[idx] = min(seg[2 * idx + 1], seg[2 * idx + 2]);
    }

    int query(int idx, int low, int high, int l, int r) 
    {
        if (l > high || r < low) return INT_MAX;
        if (l <= low && high <= r) return seg[idx];

        int mid = (low + high) / 2;

        int left = query(2 * idx + 1, low, mid, l, r);

        int right = query(2 * idx + 2, mid + 1, high, l, r);

        return min(left, right);
    }

    void update(int idx, int low, int high, int i, int nv)
    {
        if (low == high) 
        {
            seg[idx] = nv;
            return;
        }
        int mid = (low + high) / 2;
        if (i <= mid) 
        {
            update(2 * idx + 1, low, mid, i, nv);
        } 
        else 
        {
            update(2 * idx + 2, mid + 1, high, i, nv);
        }
        seg[idx] = min(seg[2 * idx + 1], seg[2 * idx + 2]);
    }
};

void solve() {
    int n1;
    cin >> n1;
    int arr1[n1];
    for (int i = 0; i < n1; i++) cin >> arr1[i];
    SGTree sg1(n1);
    sg1.build(0, 0, n1 - 1, arr1);

    int n2;
    cin >> n2;
    int arr2[n2];
    for (int i = 0; i < n2; i++) cin >> arr2[i];
    SGTree sg2(n2);
    sg2.build(0, 0, n2 - 1, arr2);

    int q;
    cin >> q;
    while (q--) 
    {
        int type;
        cin >> type;
        if (type == 1) 
        {
            int l1, r1, l2, r2;
            cin >> l1 >> r1 >> l2 >> r2;
            int min1 = sg1.query(0, 0, n1 - 1, l1, r1);
            int min2 = sg2.query(0, 0, n2 - 1, l2, r2);
            cout << min(min1, min2) << "\n";
        } 

        else 
        {
            int arrNo, i, nv;
            cin >> arrNo >> i >> nv;
            if (arrNo == 1) 
            {
                sg1.update(0, 0, n1 - 1, i, nv);
                arr1[i] = nv;
            } 
            else 
            {
                sg2.update(0, 0, n2 - 1, i, nv);
                arr2[i] = nv;
            }
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    solve();
    return 0;
}
