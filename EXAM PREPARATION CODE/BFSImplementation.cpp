
#include <bits/stdc++.h>
using namespace std;

void prepareAdj(unordered_map<int, set<int>>& adjList, vector<pair<int, int>>& edges) {
    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i].first;
        int v = edges[i].second;

        adjList[u].insert(v);
        adjList[v].insert(u);
    }
}

void bfs(int node, vector<int>& ans, unordered_map<int, set<int>>& adjList, unordered_map<int, bool>& visited) {

    // create one queue
    queue<int> q;

    // push first node 
    q.push(node);
    // mark it true
    visited[node] = true;

    //iterate untill when the que gots empty
    while (!q.empty()) {
        // pick front element 
        int frontNode = q.front();
        // pop front element
        q.pop();
        // insert to ans that front node 
        ans.push_back(frontNode);

        //traverse adj list 
        for (auto i : adjList[frontNode]) {
            // checking if visited node is marked true or not 
            if (!visited[i]) {
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

int main() {
    int n, m;
    cout << "Enter the number of nodes: ";
    cin >> n;
    cout << "Enter the number of edges: ";
    cin >> m;

    vector<pair<int, int>> edges(m);
    cout << "Enter the edges (u v):" << endl;
    for (int i = 0; i < m; i++) {
        cin >> edges[i].first >> edges[i].second;
    }

    unordered_map<int, set<int>> adjList;
    prepareAdj(adjList, edges);

    unordered_map<int, bool> visited;
    vector<int> ans;

    cout << "BFS Traversal starting from node 1:" << endl;
    bfs(1, ans, adjList, visited);

    for (int node : ans) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}