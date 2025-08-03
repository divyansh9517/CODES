#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 1e5 + 5;

int a[N];               // Ant strengths
int seg[4 * N];         // Segment Tree to store GCD
map<int, vector<int>> positions;  // Strength value → list of positions

// Segment Tree build function
void build(int id, int l, int r) {
    if (l == r) {
        seg[id] = a[l];
        return;
    }
    int mid = (l + r) / 2;
    build(2 * id, l, mid);
    build(2 * id + 1, mid + 1, r);
    seg[id] = __gcd(seg[2 * id], seg[2 * id + 1]); // Left aur right ka GCD
}

// Segment Tree query to get GCD in range [ql, qr]
int query(int id, int l, int r, int ql, int qr) {
    if (qr < l || r < ql) return 0;  // Range bahar hai
    if (ql <= l && r <= qr) return seg[id];  // Completely andar hai
    int mid = (l + r) / 2;
    int left = query(2 * id, l, mid, ql, qr);
    int right = query(2 * id + 1, mid + 1, r, ql, qr);
    return __gcd(left, right);
}

// Count how many times 'val' appears between l and r using binary search
int countGCD(int val, int l, int r) {
    if (!positions.count(val)) return 0;
    auto& vec = positions[val];
    return upper_bound(vec.begin(), vec.end(), r) - lower_bound(vec.begin(), vec.end(), l);
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    // Input strengths and store their positions
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        positions[a[i]].push_back(i);  // Value ki har position store karo
    }

    // Build segment tree
    build(1, 1, n);

    int t;
    cin >> t;

    while (t--) {
        int l, r;
        cin >> l >> r;

        // Step 1: Get GCD of range [l, r]
        int g = query(1, 1, n, l, r);

        // Step 2: Count how many ants have strength == GCD in range
        int survivors = countGCD(g, l, r);

        // Step 3: Mole eats remaining ants
        int total = r - l + 1;
        cout << total - survivors << '\n';
    }

    return 0;
}
