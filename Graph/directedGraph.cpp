#include<bits/stdc++.h>
using namespace std;

class Graph{
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
            adj[v].push_back(u);
        }
    }

    void printGrap()
    {
        for(auto i : adj)
        {
            cout<<i.first<<" -> {";
            for(auto j : i.second)
            {
                cout<<j<<",";
            }
            cout<<"}"<<endl;
        }
    }
    bool topoSortByBFS()
    {
        queue<int> q;
        unordered_map<int,int> indegree;

        // pehly hum indegree min sare numbers daal dengy unki degree ke sath
        for(auto i : adj)
        {
            for(auto j : i.second)
            {
                indegree[j]++;
            }
        }

        // push all zero indegree to queue
        // fir hum check karengy ko indegree min koi aisa element hai kya jiski value 0 hia 
        for(int i = 0; i < adj.size() ;i++)
        {
            if(indegree[i] == 0){
                // agar aisa hai tho queue min daal dengy 
                q.push(i);
            }
        }

        // bfs 
        int count = 0;
        while(!q.empty())
        {
            int frontNode = q.front();
            q.pop();
            count++;
            for(auto nbr :adj[frontNode])
            {
                // aab hum nbr ki indegree ko kam krengy 
                indegree[nbr]--;

                // agar zero hai tho 
                //queue min daal dengy
                if(indegree[nbr] == 0)
                {
                    q.push(nbr);
                }
            }
        }
        return count != adj.size();
    }
    void sortestPath(int src,int dest)
    {
        // sabse pehly ek queue bana lengy
        queue<int> q;
        // fir 2 map create  karengy  ek visit ka aur ek parent ka 
        map<int,bool>visit;
        map<int,int> parent;
        //sabse pehly source ko daal dengy
        q.push(src);
        /// visit ko true mark kr dengy
        visit[src] =true;
        parent[src] = -1;

        // bfs vala logix
        while(!q.empty())
        {
            int frontNode = q.front();
            q.pop();
            for(auto nbr : adj[frontNode])
            {
                if(!visit[nbr])
                {
                    q.push(nbr);
                    parent[nbr]= frontNode;
                    visit[nbr]=true;
                }
            }
        }

        vector<int> ans;
        while(dest != -1)
        {
            ans.push_back(dest);
            dest = parent[dest];

        }
        reverse(ans.begin(),ans.end());
        for(auto i : ans)
        {
            cout<<i<<"";
        }
    }
};

int main()
{
    Graph g;
    g.addEdge(0,5,0);
    g.addEdge(5,4,0);
    g.addEdge(4,3,0);
    g.addEdge(0,6,0);
    g.addEdge(6,3,0);
    g.addEdge(0,1,0);
    g.addEdge(1,2,0);
    g.addEdge(2,3,0);

    g.printGrap();
    // if(g.topoSortByBFS() == 0){
    //     cout<<"Cycle not found"<<endl;
    // }
    // else{
    //     cout<<"Cycle found"<<endl;
    // }
    g.sortestPath(0,3);
    return 0;


}
