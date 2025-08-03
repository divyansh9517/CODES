#include <iostream>
#include <vector>
using namespace std;


int solve(int n, const vector<int>& a, const vector<int>& b) {
    int m = 0, s = 0;
    for (int i = 0; i < n; i++) {
        if (i == n - 1) {
            m += a[i];
        } else {
            if (a[i] - b[i + 1] > 0) {
                m += a[i];
                s += b[i + 1];
            }
        }
    }
    return m - s;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        vector<int> b(n);

        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];

        int result = solve(n, a, b);
        cout << result << endl;
    }

    return 0;
}
