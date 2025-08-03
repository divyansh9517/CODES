#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

vector<int> topo(int n, vector<vector<int>> &adj) {
    vector<int> indegree(n, 0);
    for (int i = 0; i < n; i++) {
        for (auto it : adj[i]) {
            indegree[it]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    vector<int> result;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        result.push_back(node);
        for (auto it : adj[node]) {
            indegree[it]--;
            if (indegree[it] == 0) q.push(it);
        }
    }
    return result;
}

int solve(vector<vector<int>> &edges, int n, int m) {
    vector<vector<int>> adj(n);
    for (auto it : edges) {
        int u = it[0];
        int v = it[1];
        adj[u].push_back(v);
    }

    vector<int> order = topo(n, adj);
    vector<int> dp(n, 0);
    dp[0] = 1;

    for (int u : order) {
        for (int v : adj[u]) {
            dp[v] = (dp[v] + dp[u]) % MOD;
        }
    }

    return dp[n - 1];
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges(m);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        edges[i] = {u - 1, v - 1};  // Fix: convert to 0-based indexing
    }

    int ans = solve(edges, n, m);
    cout << ans << endl;
    return 0;
}
