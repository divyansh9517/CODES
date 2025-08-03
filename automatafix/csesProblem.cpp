#include <bits/stdc++.h>
using namespace std;

struct FenwickTree {
    vector<int> bit;
    int n;

    FenwickTree(int size) {
        n = size;
        bit.assign(n + 1, 0);
    }

    void update(int i, int delta) {
        while (i <= n) {
            bit[i] += delta;
            i += i & -i;
        }
    }

    int query(int i) {
        int sum = 0;
        while (i > 0) {
            sum += bit[i];
            i -= i & -i;
        }
        return sum;
    }

    int query(int l, int r) {
        return query(r) - query(l - 1);
    }
};

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Coordinate compression
    vector<int> sortedA = a;
    sort(sortedA.begin(), sortedA.end());

    for (int i = 0; i < n; i++) {
        int compressedValue = lower_bound(sortedA.begin(), sortedA.end(), a[i]) - sortedA.begin() + 1;
        a[i] = compressedValue;
    }

    FenwickTree fenw(n);
    long long inv = 0;

    // First window of size k
    for (int i = 0; i < k; i++) {
        inv += fenw.query(a[i] + 1, n);  // Count elements greater than a[i]
        fenw.update(a[i], 1);
    }

    cout << inv << " ";

    // Slide the window
    for (int i = k; i < n; i++) {
        // Remove the element going out of the window
        fenw.update(a[i - k], -1);
        inv -= fenw.query(1, a[i - k] - 1);

        // Add the new element
        inv += fenw.query(a[i] + 1, n);
        fenw.update(a[i], 1);

        cout << inv << " ";
    }

    cout << endl;
    return 0;
}

