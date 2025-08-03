#include <bits/stdc++.h>
using namespace std;

int dp[501][501];

int minCuts(int a, int b) {
    if (a == b) return 0;
    if (dp[a][b] != -1) return dp[a][b];
    
    int ans = INT_MAX;

    for (int i = 1; i <= a / 2; ++i) {
        ans = min(ans, 1 + minCuts(i, b) + minCuts(a - i, b));
    }

    for (int j = 1; j <= b / 2; ++j) {
        ans = min(ans, 1 + minCuts(a, j) + minCuts(a, b - j));
    }

    return dp[a][b] = ans;
}

int main() {
    int a, b;
    cin >> a >> b;

    memset(dp, -1, sizeof(dp));

    cout << minCuts(a, b) << endl;

    return 0;
}
