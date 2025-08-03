#include <iostream>
#include <string>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int n = stoi(s);
        bool found = false;

        for (int i = 0; i <= 99; i++) {
            for (int j = 0; j <= 99; j++) {
                if ((i + j) * (i + j) == n) {
                    cout << i << " " << j << endl;
                    found = true;
                    break;
                }
            }
            if (found) break;
        }

        if (!found) cout << -1 << endl;
    }
    return 0;
}
