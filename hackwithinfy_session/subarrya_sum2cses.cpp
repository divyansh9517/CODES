// #include<bits/stdc++.h>
// #define ll long long int
// using namespace std;

// ll solve(ll n , ll x , vector<ll> arr) {
//     unordered_map<ll ,ll> mpp;
//     mpp[0] = 1;
//     ll cnt = 0; 
//     ll sum = 0;
//     for(int i = 0 ; i < n; i++) {
//         sum += arr[i];
//         cnt += mpp[sum - x];
//         mpp[sum] += 1;
//     }
//     return cnt;
// }

// int main(){
    

//     ll n;
//     ll x;
//     cin >> n >> x;
//     vector<ll> arr(n);
//     for(ll i = 0 ; i < n ; i++) {
//         cin >> arr[i];
//     }

//     ll ans = solve(n, x, arr);
//     cout << ans << "\n";
//     return 0;
// }

#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N, X;
	cin >> N >> X;
	vector<int> T(N);
	for (int i = 0; i < N; i++) { cin >> T[i]; }

	long long prefix_sum = 0;
	long long ans = 0;
	map<long long, int> sums;
	sums[0] = 1;
	for (int x : T) {
		prefix_sum += x;
		ans += sums[prefix_sum - X];
		sums[prefix_sum]++;
	}
	cout << ans << endl;
}