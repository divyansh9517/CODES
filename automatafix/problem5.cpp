#include <bits/stdc++.h>
using namespace std;
int main() {
    
    int n, k;
    cin >> n >> k;

    long long x, a, b, c;
    cin >> x >> a >> b >> c;

    vector<int> arr(n);
    arr[0] = x;

    for (int i = 1; i < n; ++i) {
        arr[i] = (a * arr[#include <bits/stdc++.h>
using namespace std;
int main() {
    
    int n, k;
    cin >> n >> k;

    long long x, a, b, c;
    cin >> x >> a >> b >> c;

    vector<int> arr(n);
    arr[0] = x;

    for (int i = 1; i < n; ++i) {
        arr[i] = (a * arr[i - 1] + b) % c;
    }


    int windowXOR = 0;
    for (int i = 0; i < k; ++i) {
        windowXOR ^= arr[i];
    }

    int result = windowXOR;

    for (int i = k; i < n; ++i) {
        windowXOR ^= arr[i - k];  
        windowXOR ^= arr[i];      
        result ^= windowXOR;     
    }

    cout << result << '\n';
    return 0;
}i - 1] + b) % c;
    }


    int windowXOR = 0;
    for (int i = 0; i < k; ++i) {
        windowXOR |= arr[i];
    }

    int result = windowXOR;

    for (int i = k; i < n; ++i) {
        windowXOR |= arr[i - k];  
        windowXOR |= arr[i];      
        result |= windowXOR;     
    }

    cout << result << '\n';
    return 0;
}