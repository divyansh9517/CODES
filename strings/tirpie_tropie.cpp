#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    cin.ignore(); 

    while (t--) {
        string st;
        getline(cin, st);

        string ans;
        if (!st.empty())
            ans += st[0]; 

        for (int i = 1; i < st.size(); i++) {
            if (st[i - 1] == ' ') {
                ans += st[i]; 
            }
        }
        cout << ans << endl;
    }

    return 0;
}
