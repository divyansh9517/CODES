#include <iostream>
#include <vector>
using namespace std;

bool isPossible(const vector<int>& b) {
    int n = b.size();
    for (int i = n - 2; i >= 0; --i) {
        if (b[i] > b[i + 1] + 1) {
            return false;
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; 
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> b(n);
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }

        cout << (isPossible(b) ? "YES\n" : "NO\n");
    }

    return 0;
}
