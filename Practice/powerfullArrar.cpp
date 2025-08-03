#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e6 + 5;
int BLOCK_SIZE, n, m;
int A[N], ans[N], freq[N];
int currAns = 0;

struct Query {
    int l, r, idx;
};

bool cmp(Query a, Query b) {
    int t1 = a.l / BLOCK_SIZE;
    int t2 = b.l / BLOCK_SIZE;
    if (t1 != t2)
        return t1 < t2;
    return a.r < b.r;
}

void operate(int idx, int delta) {
    int x = A[idx];
    if (x >= N) return;

    // puraney valonn ko hata rahy hai 
    currAns -= freq[x] * freq[x] * x;

    // update freq
    freq[x] += delta;

    // naye contributions aadd kr rhy hai hai
    currAns += freq[x] * freq[x] * x;
}

signed main() {
    cin >> n >> m;
    BLOCK_SIZE = sqrt(n);

    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    vector<Query> queries(m);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        --x, --y; 
        queries[i] = {x, y, i};
    }

    sort(queries.begin(), queries.end(), cmp);

    int l = 0, r = -1;
    for (auto q : queries) {
        while (r < q.r) operate(++r, 1);
        while (l > q.l) operate(--l, 1);
        while (l < q.l) operate(l++, -1);
        while (r > q.r) operate(r--, -1);

        ans[q.idx] = currAns;
    }

    for (int i = 0; i < m; i++) {
        cout << ans[i] << '\n';
    }

    return 0;
}
