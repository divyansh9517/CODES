#include <bits/stdc++.h>
using namespace std;

class STMin {
    vector<int> seg, lazy; 
public: 
    STMin(int n) {
        seg.resize(4 * n); 
        lazy.resize(4 * n); 
    }
    
public: 
    void build(int ind, int low, int high, int arr[]) {
        if(low == high) {
            seg[ind] = arr[low];
            return; 
        }
        int mid = (low + high) >> 1; 
        build(2*ind+1, low, mid, arr); 
        build(2*ind+2, mid+1, high, arr); 
        seg[ind] = min(seg[2*ind+1], seg[2*ind+2]);
    }
    
public:
    void update(int ind, int low, int high, int l, int r, int val) {
        // update the previous remaining updates 
        // and propogate downwards 
        if(lazy[ind] != 0) {
            seg[ind] += lazy[ind]; 
            // propogate the lazy update downwards
            // for the remaining nodes to get updated 
            if(low != high) {
                lazy[2*ind+1] += lazy[ind]; 
                lazy[2*ind+2] += lazy[ind]; 
            }
            lazy[ind] = 0; 
        }

        // no overlap 
        // we don't do anything and return 
        // low high l r or l r low high 
        if(high < l || r < low) {
            return; 
        }

        // complete overlap 
        // l low high r 
        if(low >= l && high <= r) {
            seg[ind] += val; 
            // if not a leaf node, it will have children
            if(low != high) {
                lazy[2*ind+1] += val; 
                lazy[2*ind+2] += val; 
            }
            return; 
        }
        
        // partial overlap case
        int mid = (low + high) >> 1; 
        update(2*ind+1, low, mid, l, r, val);
        update(2*ind+2, mid+1, high, l, r, val); 
        seg[ind] = min(seg[2*ind+1], seg[2*ind+2]); 
    }
    
public: 
    int query(int ind, int low, int high, int l, int r) {
        // update if any updates are remaining 
        // as the node will stay fresh and updated 
        if(lazy[ind] != 0) {
            seg[ind] += lazy[ind]; 
            // propogate the lazy update downwards
            // for the remaining nodes to get updated 
            if(low != high) {
                lazy[2*ind+1] += lazy[ind]; 
                lazy[2*ind+2] += lazy[ind]; 
            }
            lazy[ind] = 0; 
        }

        // no overlap return INT_MAX for minimum queries
        if(high < l || r < low) {
            return INT_MAX; 
        }

        // complete overlap 
        if(low >= l && high <= r) {
            return seg[ind]; 
        }

        // partial overlap
        int mid = (low + high) >> 1; 
        int left = query(2*ind+1, low, mid, l, r);
        int right = query(2*ind+2, mid+1, high, l, r);
        return min(left, right); 
    }
};

    int main() {
    int n;
    cin >> n;

    if (n <= 0) {
        cout << "Invalid array size\n";
        return 0;
    }

    int* arr = new int[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    STMin st(n);
    st.build(0, 0, n-1, arr);

    int q;
    cin >> q;

    if (q < 0) {
        cout << "Invalid number of queries\n";
        delete[] arr;
        return 0;
    }

    while(q--) {
        int type;
        cin >> type;

        if(type == 1) {
            int l, r;
            cin >> l >> r;

            if(l < 0 || r >= n || l > r) {
                cout << "Invalid query range\n";
                continue;
            }

            cout << st.query(0, 0, n-1, l, r) << "\n";
        }
        else if(type == 2) {
            int l, r, val;
            cin >> l >> r >> val;

            if(l < 0 || r >= n || l > r) {
                cout << "Invalid update range\n";
                continue;
            }

            st.update(0, 0, n-1, l, r, val);
        }
        else {
            cout << "Invalid operation type\n";
        }
    }

    delete[] arr;
    return 0;
}

