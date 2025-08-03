#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, c;
    cin >> n >> c;
    vector<int> A(n);
    for (int &x : A) cin >> x;

    int cur = 0, minPrefix = 0;
    for (int i = 0; i < n; ++i) {
        if (A[i] == -1) cur--;
        else if (A[i] == 1) {
            if (cur < c) cur++;
        }
        minPrefix = min(minPrefix, cur);
    }

    int result = max(0, -minPrefix);
    cout << result << "\n";
    return 0;
}
