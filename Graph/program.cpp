#include<bits/stdc++.h>
using namespace std;

void solve(vector<vector<int>> &adj,int u,int v)
{
    adj[u][v] = 1;
    adj[v][u] = 1;
}

void print(vector<vector<int>> &adj)
{
    for(int i = 0 ; i < adj.size() ; i++)
    {
        for(int j  = 0 ; j < adj[0].size() ; j++)
        {
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main(){
    int v = 5;
    vector<vector<int>> adj(v+1,vector<int>(v+1,0));

    solve(adj,4,5);
    solve(adj,3,1);
    solve(adj,2,1);
    solve(adj,2,4);

    print(adj);
    
}