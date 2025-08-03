#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; 
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;

        int count0 = 0, count1 = 0;
        for (char c : s) {
            if (c == '0') count0++;
            else count1++;
        }

        int totalPairs = n / 2;
        int b = totalPairs - k;

        // Calculate bounds for x
        int low = max(0, k - (count1 - b) / 2);
        int high = min(k, (count0 - b) / 2);

        if (low <= high) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}
