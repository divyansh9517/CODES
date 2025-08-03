#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> parent, minWeight;

    DSU(int n) {
        parent.resize(n);
        minWeight.assign(n, 1e9);
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int x) {
        if (x != parent[x])
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int x, int y, int w) {
        x = find(x);
        y = find(y);
        if (x == y) return;

        parent[y] = x;
        minWeight[x] = min({minWeight[x], minWeight[y], w});
    }

    bool connected(int x, int y) {
        return find(x) == find(y);
    }

    int getMinWeight(int x) {
        return minWeight[find(x)];
    }
};

struct Edge {
    int w, u, v;
};

bool cmp(const Edge &a, const Edge &b) {
    return a.w < b.w;
}

void solve() {
    int n, m;
    cin >> n >> m;

    vector<Edge> edges(m);
    for (int i = 0; i < m; ++i) {
        int w, u, v;
        cin >> u >> v >> w;
        u--, v--;
        edges[i] = {w, u, v};
    }

    sort(edges.begin(), edges.end(), cmp);
    DSU dsu(n);
    int ans = 2e9;

    for (const auto &e : edges) {
        dsu.unite(e.u, e.v, e.w);
        if (dsu.connected(0, n - 1)) {
            ans = min(ans, dsu.getMinWeight(0) + e.w);
        }
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
