#include <bits/stdc++.h>
using namespace std;
#define int long long

class Sgt {
private:
    int n; // size of array
    vector<int> arr; // strength of ants
    vector<int> segment; // segment tree
    map<int, vector<int>> position; // stores positions of each strength value

    // Segment Tree build function
    void build(int idx, int low, int high) {
        if (low == high) {
            segment[idx] = arr[low];
            return;
        }
        int mid = (low + high) / 2;
        build(2 * idx + 1, low, mid);
        build(2 * idx + 2, mid + 1, high);
        segment[idx] = __gcd(segment[2 * idx + 1], segment[2 * idx + 2]);
    }

    // Segment Tree query function for GCD in range [l, r]
    int query(int idx, int low, int high, int l, int r) {
        if (r < low || high < l) return 0; // no overlap
        if (l <= low && high <= r) return segment[idx]; // complete overlap
        int mid = (low + high) / 2;
        int left = query(2 * idx + 1, low, mid, l, r);
        int right = query(2 * idx + 2, mid + 1, high, l, r);
        return __gcd(left, right);
    }

    // Count how many times value `val` appears in range [l, r]
    int count(int val, int l, int r) {
        if (!position.count(val)) return 0;
        auto& vec = position[val];
        return upper_bound(vec.begin(), vec.end(), r) - lower_bound(vec.begin(), vec.end(), l);
    }

public:
    // Constructor
    Sgt(int size) {
        n = size;
        arr.resize(n + 1); // 1-based indexing
        segment.resize(4 * (n + 1));
    }

    // Input strengths and prepare position map and segment tree
    void inputStrengths() {
        for (int i = 1; i <= n; ++i) {
            cin >> arr[i];
            position[arr[i]].push_back(i); // har value ke liye uske indices store kiye
        }
        build(0, 1, n); // Segment tree ko build kiya
    }

    // Process all queries
    void processQueries(int t) {
        while (t--) {
            int l, r;
            cin >> l >> r;
            int gcdInRange = query(0, 1, n, l, r); // GCD nikaala segment tree se
            int survivors = count(gcdInRange, l, r); // jo ants bache honge unka count
            int total = r - l + 1; // total ants
            cout << total - survivors << '\n'; // Mole will eat the rest
        }
    }
};

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    Sgt colony(n);             // Object banaya class ka
    colony.inputStrengths();   // Ant strengths input li and segment tree banaya

    int t;
    cin >> t;
    colony.processQueries(t);  // Sabhi queries process ki

    return 0;
}
