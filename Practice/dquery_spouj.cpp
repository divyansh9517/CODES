#include <bits/stdc++.h>
using namespace std;
 
const int MAXN = 3e4 + 5;
const int MAXA = 1e6 + 5;
const int BLOCK_SIZE = 174; 
 
struct Query {
    int l, r, idx;
    bool operator<(const Query &other) const {
        if (l / BLOCK_SIZE != other.l / BLOCK_SIZE)
            return l / BLOCK_SIZE < other.l / BLOCK_SIZE;
        return r < other.r;
    }
};
 
int n, q;
int a[MAXN], ans[MAXN];
int freq[MAXA], curr_ans = 0;
 
void add(int idx) {
    freq[a[idx]]++;
    if (freq[a[idx]] == 1) curr_ans++;
}
 
void remove(int idx) {
    freq[a[idx]]--;
    if (freq[a[idx]] == 0) curr_ans--;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
 
    cin >> q;
    vector<Query> queries(q);
    for (int i = 0; i < q; i++) {
        cin >> queries[i].l >> queries[i].r;
        queries[i].l--, queries[i].r--; 
        queries[i].idx = i;
    }
 
    sort(queries.begin(), queries.end());
 
    int l = 0, r = -1;
 
    for (const auto &query : queries) {
        while (l > query.l) add(--l);
        while (r < query.r) add(++r);
        while (l < query.l) remove(l++);
        while (r > query.r) remove(r--);
 
        ans[query.idx] = curr_ans;
    }
 
    for (int i = 0; i < q; i++) {
        cout << ans[i] << "\n";
    }
 
    return 0;
}