#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;

        vector<int> A(n + 1);
        for (int i = 1; i <= n; ++i) {
            cin >> A[i];
        }
        vector<pair<int, int>> roads;
        int first = 1;
        int different = -1;

        for (int i = 2; i <= n; ++i) {
            if (A[i] != A[first]) {
                different = i;
                roads.emplace_back(first, i);
            }
        }
        if (different == -1) {
            cout << "NO\n";
            continue;
        }
        for (int i = 2; i <= n; ++i) {
            if (A[i] == A[first]) {
                roads.emplace_back(i, different);
            } else if (i != different) {
                roads.emplace_back(first, i);
            }
        }
        cout << "YES\n";
        for (auto [u, v] : roads) {
            cout << u << " " << v << "\n";
        }
    }
    return 0;
}
