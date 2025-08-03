#include<bits/stdc++.h>
using namespace std;

int solve(int target,vector<int> &coins) {
    //  recursive solution

    // if (idx == 0) {
    //     if (target % coins[idx] == 0) {
    //         return target / coins[idx];
    //     } else {
    //         return 1e9; 
    //     }
    // }

    // int not_taken = solve(idx - 1, target, coins);
    // int taken = 1e9;

    // if (coins[idx] <= target) {
    //     taken = 1 + solve(idx, target - coins[idx], coins); 
    // }

    // return min(not_taken, taken);


    //greedy solution
    int cnt = 0;
    for(int i : coins)
    {
        cnt += target/i;
        target %= i;
    }
    return cnt;

}

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
