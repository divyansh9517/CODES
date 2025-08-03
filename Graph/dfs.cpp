#include<bits/stdc++.h>

using namespace std;

class Graph{
    public:
    
    unordered_map<int , list<int>> adjList;

    void addEdges(int u ,int v , bool direction)
    {
        // direction -> 0 // undirected
        // direction -> 1 // directed
        

        if(direction == 1)
        {
            adjList[u].push_back(v);
        }

        else{

            // u -> v
            adjList[u].push_back(v);

            // v -> u
            adjList[v].push_back(u);
        }
        cout<<"printing list"<<endl;
        printList();
        cout<<endl;
    }

    void printList(){
        for(auto i : adjList)
        {
            cout<<i.first<<" ->";
            for(auto j : i.second)
            {
                cout<<j<<",";
            }
            cout<<endl;
        }
    }
    void dfs(int src , unordered_map<int,bool>& vis)
    {
        vis[src] = true;
        cout<<src<<" ";
        for(auto nbr : adjList[src])
        {
            int data = nbr;
            if(!vis[data])
            {
                dfs(nbr,vis);
            }
        }
    }
};

int main(){
    Graph  g;
    // g.addEdges(0,1,0);
    // g.addEdges(1,2,0);
    // g.addEdges(1,3,0);
    // g.addEdges(2,3,0);

    g.addEdges(0,1,1);
    g.addEdges(1,2,1);
    g.addEdges(1,3,1);
    g.addEdges(2,3,1);

    cout<<"Printing DFS : - ";
    unordered_map<int,bool> vis;

    for(int i = 0 ; i <= 3 ; i++)
    {
        if(!vis[i])
        {
            g.dfs(i,vis);
        }
    }
    return 0;
    
}