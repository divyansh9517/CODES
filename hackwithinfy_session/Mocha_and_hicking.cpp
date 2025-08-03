// #include <bits/stdc++.h>
// using namespace std;

// // Perform topological sort using Kahn's algorithm
// vector<int> topoSort(vector<vector<int>>& graph, int total) {
//     vector<int> indegree(total + 1, 0);
//     for (int u = 1; u <= total; ++u) {
//         for (int v : graph[u]) {
//             indegree[v]++;
//         }
//     }

//     queue<int> q;
//     for (int i = 1; i <= total; ++i) {
//         if (indegree[i] == 0) {
//             q.push(i);
//         }
//     }

//     vector<int> order;
//     while (!q.empty()) {
//         int node = q.front(); q.pop();
//         order.push_back(node);

//         for (int v : graph[node]) {
//             indegree[v]--;
//             if (indegree[v] == 0) {
//                 q.push(v);
//             }
//         }
//     }

//     return order;
// }

// void solve(int n, vector<int>& a) {
//     int total = n + 1;
//     vector<vector<int>> graph(total + 1);
//     vector<vector<bool>> edge(total + 1, vector<bool>(total + 1, false));

//     // Add roads: i -> i+1 for 1 <= i <= n-1
//     for (int i = 1; i < n; ++i) {
//         graph[i].push_back(i + 1);
//         edge[i][i + 1] = true;
//     }

//     // Add roads based on array a
//     for (int i = 1; i <= n; ++i) {
//         if (a[i - 1] == 0) {
//             graph[i].push_back(total);     // i -> n+1
//             edge[i][total] = true;
//         } else {
//             graph[total].push_back(i);     // n+1 -> i
//             edge[total][i] = true;
//         }
//     }

//     vector<int> order = topoSort(graph, total);

//     // Validate the topological order forms a direct path
//     bool valid = true;
//     for (int i = 0; i < order.size() - 1; ++i) {
//         if (!edge[order[i]][order[i + 1]]) {
//             valid = false;
//             break;
//         }
//     }

//     if (valid && order.size() == total) {
//         for (int x : order) {
//             cout << x << " ";
//         }
//         cout << "\n";
//     } else {
//         cout << "-1\n";
//     }
// }

// int main() {
//     int t;
//     cin >> t;
//     while (t--) {
//         int n;
//         cin >> n;
//         vector<int> a(n);
//         for (int i = 0; i < n; ++i) {
//             cin >> a[i];
//         }
//         solve(n, a);
//     }
//     return 0;
// }


#include<bits/stdc++.h>
using namespace std;
 
void solve(int n , vector<int> &a) {
    int pos = -1;
    // Case 1: If a[0] == 1 → n+1 can be at beginning
    if(a[0] == 1) {
        cout << n+1 << " ";
        for(int i = 1; i <= n; i++) {
            cout << i << " ";
        }
        cout << "\n";
        return;
    }
 
    // Case 2: If a[n-1] == 0 → n+1 can be at end
    if(a[n-1] == 0) {
        for(int i = 1; i <= n; i++) {
            cout << i << " ";
        }
        cout << n+1 << "\n";
        return;
    }
 
    // Case 3: Find any i such that a[i]==0 and a[i+1]==1
    for(int i = 0; i < n - 1; i++) {
        if(a[i] == 0 && a[i+1] == 1) {
            pos = i+1;
            break;
        }
    }
 
    if(pos == -1) {
        cout << "-1\n";
        return;
    }
 
    // Insert n+1 between pos and pos+1
    for(int i = 1; i <= pos; i++) {
        cout << i << " ";
    }
    cout << n+1 << " ";
    for(int i = pos+1; i <= n; i++) {
        cout << i << " ";
    }
    cout << "\n";
}
 
int main() {
    int t;
    cin >> t;
    while(t--) {
        int n ; 
        cin >> n;
        vector<int> a(n);
        for(int i = 0 ; i < n; i++) {
            cin >> a[i];
        }
        solve(n,a);
    }
    return 0;
}
