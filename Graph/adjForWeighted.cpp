#include<bits/stdc++.h>

using namespace std;

class Graph{
    public:
    
    unordered_map<int , list<pair<int,int>>> adjList;

    void addEdges(int u ,int v ,int wt, bool direction)
    {
        // direction -> 0 // undirected
        // direction -> 1 // directed
        

        if(direction == 1)
        {
            adjList[u].push_back(make_pair(v,wt));
        }

        else{

            // u -> v
            adjList[u].push_back(make_pair(v,wt));

            // v -> u
            adjList[v].push_back(make_pair(u,wt));
        }
        cout<<"printing list"<<endl;
        printList();
        cout<<endl;
    }

    void printList(){
        for(auto i : adjList)
        {
            cout<<i.first<<" -> { ";
            for(pair<int,int> j : i.second)
            {
                cout<<"{"<<j.first<<","<<j.second<<"},";
            }
            cout<<"}"<<endl;
        }
    }
};

int main(){
    Graph  g;
    // g.addEdges(0,1,0);
    // g.addEdges(1,2,0);
    // g.addEdges(1,3,0);
    // g.addEdges(2,3,0);

    g.addEdges(0,1,4,1);
    g.addEdges(1,2,5,1);
    g.addEdges(1,3,7,1);
    g.addEdges(2,3,8,1);
    
}