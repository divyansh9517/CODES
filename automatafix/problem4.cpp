#include <iostream>
#include <vector>
using namespace std;

const int MOD = 998244353;
const int MAX = 1e6 + 10;

int n;
long long m;
int mu[MAX];


long long mod_pow(long long base, long long exp) 
{
    long long res = 1;
    base %= MOD;
    while (exp > 0)
    {
        if (exp % 2 == 1)
            res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

void compute_mobius() {
    for (int i = 1; i < MAX; ++i)
        mu[i] = 1;

    for (int i = 2; i < MAX; ++i)
    {
        if (mu[i] == 1) 
        {
            for (int j = i; j < MAX; j += i)
                mu[j] *= -1;
            for (long long j = 1LL * i * i; j < MAX; j += i * i)
                mu[j] = 0;
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n - 1; ++i) 
    {
        int u, v;
        cin >> u >> v;
    }

    compute_mobius();

    long long result = 0;

    for (int d = 1; d <= m; ++d) 
    {
        if (mu[d] == 0) continue;
        long long cnt = m / d;
        long long ways = mod_pow(cnt, n);
        result = (result + mu[d] * ways + MOD) % MOD;
    }

    cout << result << endl;
    return 0;
}
