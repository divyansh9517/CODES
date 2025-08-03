#include <bits/stdc++.h>
using namespace std;

void f(vector<vector<int>> &adjMat, int u, int v) {
    adjMat[u][v] = 1;
    adjMat[v][u] = 1; 
}

void print(vector<vector<int>> &adjMat) {
    int n = adjMat.size();
    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < n ; j++) {
            cout << adjMat[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int n = 6; 
    vector<vector<int>> adjMat(n, vector<int>(n, 0));

    f(adjMat, 1, 2);
    f(adjMat, 2, 3);
    f(adjMat, 3, 5);
    f(adjMat, 4, 5);
    f(adjMat, 4, 2);
    f(adjMat, 1, 3);

    print(adjMat);

    return 0;
}
