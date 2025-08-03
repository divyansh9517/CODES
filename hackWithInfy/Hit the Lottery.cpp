#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> coins = {1, 5, 10, 20, 100};
    int cnt = 0;

    for (int i = coins.size() - 1; i >= 0; i--) {  
        while (n >= coins[i]) {
            n -= coins[i];  
            cnt++;
        }
    }

    cout << cnt << endl;  
    return 0;
}