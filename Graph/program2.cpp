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

    void bfs(int src,vector<int> &vis)
    {
        queue<int>  q;
        q.push(src);
        vis[src] = 1;

        while(!q.empty())
        {
            int frontNode = q.front();
            cout<<frontNode<<" ";
            q.pop();
            for(auto nbr : adjList[frontNode])
            {
                int data = nbr;
                if(!vis[data])
                {
                    q.push(data);
                    vis[data]= 1;
                }
            }
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

    vector<int> vis(4,0);
    for(int i = 0 ; i <= 3 ; i++)
    {
        if(!vis[i])
        {
            g.bfs(i,vis);
        }
    }
}
