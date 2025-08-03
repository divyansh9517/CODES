#include<bits/stdc++.h>
using namespace std;

class Graph
{
    public:
    unordered_map<int,list<int>> adj;
    void addEdge(int u,int v,bool direction)
    {
        if(direction == 1)
        {
            adj[u].push_back(v);
        }
        else{
            adj[u].push_back(v);
            adj[v].push_back(v);
        }

    }

    void printAdjList()
    {
        for(auto i : adj)
        {
            cout<<i.first<<" -> {";
            for(auto j :i.second)
            {
                cout<<j<<",";
            }
            cout<<"}"<<endl;

        }
    }

    //using dfs
    void topoSort(int src,map<int,bool> &visit,stack<int> &st)
    {
        visit[src]= true;
        for(auto neighbour : adj[src])
        {
            if(!visit[neighbour])
            {
                topoSort(neighbour,visit,st);
            }
        }
        st.push(src);
    }

    //using bfs

    void topSort(int n)
    {
        queue<int> q;
        unordered_map<int,int> indegree;
        //initialising indegree
        for(auto i : adj)
        {
            for(auto nbr : i.second)
            {
                indegree[nbr]++;
            }
        }

        // push all zero indegree vali node 
        for(int i = 0 ; i < n ; i++)
        {
            if(indegree[i] == 0)
            {
                q.push(i);
            }
        }
        // ab bfs chalaty hia 
        while(!q.empty())
        {
            int frontNode = q.front();
            q.pop();
            cout<<frontNode<<" ";
            for(auto nbr : adj[frontNode])
            {
                indegree[nbr]--;
                //check for zero 
                if(indegree[nbr] == 0)
                {
                    q.push(nbr);
                }
            }
        }
    }

};

int main()
{
    Graph g;
    g.addEdge(0,1,1);
    g.addEdge(1,2,1);
    g.addEdge(2,3,1);
    g.addEdge(2,4,1);
    g.addEdge(3,5,1);
    g.addEdge(4,5,1);
    g.addEdge(5,6,1);
    g.addEdge(5,7,1);

    g.printAdjList();
    int n = 8;

    g.topSort(n);
    // map<int,bool>visit;
    // stack<int> st;
    // for(int i = 0; i < n ; i++)
    // {
    //     if(!visit[i])
    //     {
    //         g.topoSort(i,visit,st);
    //     }
    // }

    // cout<<"Printing Topological sorted order"<<endl;
    // while(!st.empty())
    // {
    //     cout<<st.top()<<" ";
    //     st.pop();
    // }
    // cout<<endl;
    return 0;
}