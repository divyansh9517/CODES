#include <bits/stdc++.h>
using namespace std;

class graph {
public:
    unordered_map<int, list<int>> adj;

    void addList(int u, int v, bool direction) {
        adj[u].push_back(v);
        if (direction == 0) {
            adj[v].push_back(u);
        }
    }

    void printAdj() {
        for (auto i : adj) {
            cout << i.first << " -> ";
            for (auto j : i.second) {
                cout << j << ", ";
            }
            cout << endl;
        }
    }
};

int main() {
    // int n;
    // cout << "Enter the number of nodes: " << endl;
    // cin >> n;
    // int m;
    // cout << "Enter the number of edges: " << endl;
    // cin >> m;
    // graph g;
    // for (int i = 0; i < m; i++) {
    //     int u, v;
    //     cin >> u >> v;
    //     g.addList(u, v, 0);
    // }
    graph g;
    g.addList(0,1,0);
    g.addList(2,1,0);
    g.addList(3,1,0);
    g.addList(4,1,0);
    g.addList(4,2,0);
    g.addList(2,3,0);
    g.printAdj();
    return 0;
}