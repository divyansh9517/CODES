#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
const int MAXVAL = 1e6 + 5;

struct Query {
    int l, r, idx;
};

int n, t, block_size;
int a[MAXN], cnt[MAXVAL];
long long answers[MAXN];
long long current_power = 0;

vector<Query> queries;

bool cmp(Query& x, Query& y) {
    int block_x = x.l / block_size;
    int block_y = y.l / block_size;
    if (block_x != block_y)
        return block_x < block_y;
    return x.r < y.r;
}

void add(int idx) {
    int val = a[idx];
    current_power += (1LL * (2 * cnt[val] + 1) * val);
    cnt[val]++;
}

void remove(int idx) {
    int val = a[idx];
    current_power -= (1LL * (2 * cnt[val] - 1) * val);
    cnt[val]--;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> t;
    block_size = sqrt(n);

    for (int i = 0; i < n; i++) cin >> a[i];

    for (int i = 0; i < t; i++) {
        int l, r;
        cin >> l >> r;
        queries.push_back({l - 1, r - 1, i}); // 0-based
    }

    sort(queries.begin(), queries.end(), cmp);

    int l = 0, r = -1;
    for (auto q : queries) {
        while (l > q.l) add(--l);
        while (r < q.r) add(++r);
        while (l < q.l) remove(l++);
        while (r > q.r) remove(r--);
        answers[q.idx] = current_power;
    }

    for (int i = 0; i < t; i++) cout << answers[i] << '\n';

    return 0;
}
