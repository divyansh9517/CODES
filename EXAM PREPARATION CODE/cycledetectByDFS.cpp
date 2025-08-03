#include<bits/stdc++.h>
using namespace std;

bool isCycleDFS(int node,int parent ,unordered_map<int,bool>&visited,unordered_map<int,list<int>>&adj)
{
    visited[node] = true;
    for(auto i :adj[node])
    {
        if(!visited[i])
        {
            bool cycleDetected = isCycleDFS(node,parent,visited,adj);
            if(cycleDetect)
            {
                return true;
            }
        }
        else if(neighbour != parent)
        {
            return true;
        }
    }
    return false;
}

string cycleDetect(vector<vector<int>>& edges,int n , int m)
{
    unordered_map<int,list<int>> adj;
    for(int i = 0;i<m; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    unordered_map<int,bool> visited;
    for(int i = 0; i < n ; i++)
    {
        if(!visited[i])
        {
            bool ans = isCycleDFS(i,-1,visited,adj);
            if(ans == 1)
            {
                return " yes";
            }
        }
    }
    return "No";
}