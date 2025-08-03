#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; 
    cin >> t;

    while (t--) {
        int n;
        long long c;
        cin >> n >> c;

        vector<long long> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];

        sort(a.begin(), a.end()); // Greedy: destroy smallest weights first

        int coins = 0;
        for (int i = 0; i < n; ++i) {
            long long weight = a[i] << i; // multiply by 2^i
            if (weight > c) coins++; // if after multiplying it goes above limit, pay 1 coin
        }

        cout << coins << "\n";
    }

    return 0;
}
