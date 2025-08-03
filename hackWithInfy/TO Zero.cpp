#include<bits/stdc++.h>
using namespace std;

long long solve(long long n, long long k)
{
    long long maxOdd = k;
    long long maxEven = k-1;

    if(n% 2 == 1)
    {
        if(n <= maxOdd)
        {
            return 1;
        }
        else{
            long long rem = n - maxOdd;
            return 1 + (rem+maxEven-1)/maxEven;
        }
    }
    else{
        return(n+maxEven-1)/maxEven;
    }
    
}

int main() {
    int t; 
    cin >> t;
    while (t--) {
        long long n, k;
        cin >> n >> k;
        cout << solve(n, k) << "\n";
    }
    return 0;
}