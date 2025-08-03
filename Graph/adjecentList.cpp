#include<bits/stdc++.h>
using namespace std;
class Graph {
public:
    vector<vector<int>> adjList;

    Graph(int vertices) {
        adjList.resize(vertices);
    }

    void addEdges(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u);

        
    }

    void printList() {
        for (int i = 0; i < adjList.size(); i++) {
            cout << i << " -> ";
            for (int j : adjList[i]) {
                cout << j << ",";
            }
            cout << endl;
        }
    }
};

int main() {
    Graph g(4);
    g.addEdges(0, 1);
    g.addEdges(1, 2);
    g.addEdges(1, 3);
    g.addEdges(2, 3);

    cout << "printing list" << endl;
        g.printList();
        cout << endl;
}
