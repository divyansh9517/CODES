#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, cost;
    bool operator<(const Edge& other) const {
        return cost < other.cost; 
    }
};

int find(int x, vector<int>& parent) {
    if (x != parent[x]) {
        parent[x] = find(parent[x], parent);
    }
    return parent[x];
}

bool unionSet(int x, int y, vector<int>& parent, vector<int>& rank) {
    int parent_x = find(x, parent);
    int parent_y = find(y, parent);

    if (parent_x == parent_y) return false;

    if (rank[parent_x] > rank[parent_y]) {
        parent[parent_y] = parent_x;
    } else if (rank[parent_x] < rank[parent_y]) {
        parent[parent_x] = parent_y;
    } else {
        parent[parent_x] = parent_y;
        rank[parent_y]++;
    }
    return true;
}

int main() {
    int n, m;
    cin >> n >> m; 

    vector<Edge> edges(m);
    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].cost;
        edges[i].u--; 
        edges[i].v--;
    }

    sort(edges.begin(), edges.end()); 

    vector<int> parent(n), rank(n, 0);
    for (int i = 0; i < n; i++) parent[i] = i; 

    long long totalCost = 0;
    int edgesUsed = 0;

    for (Edge& e : edges) {
        if (unionSet(e.u, e.v, parent, rank)) {
            totalCost += e.cost;
            edgesUsed++;
        }
    }

    if (edgesUsed == n - 1) {
        cout << totalCost << endl; // MST found
    } else {
        cout << "IMPOSSIBLE" << endl; // Graph is not connected
    }

    return 0;
}
