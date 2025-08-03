#include<bits/stdc++.h>
using namespace std;

class solution{
    public :
    int solve(vector<vector<char>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<pair<int,int>,int>> q;
        vector<vector<int>> vis(n,vector<int>(m,0));

        for(int i= 0 ; i < n ;i++)
        {
            for(int j = 0 ; j < m ; j++)
            {
                if(grid[i][j] == 'A')
                {
                    q.push({{i,j},0});
                    vis[i][j] = 2;
                }
                else{
                    vis[i][j] = 0;
                }
            }
        }
        int time = 0; 
        int delRow[] = {-1,0,1,0};
        int delCol[] = {0,1,0,-1};
        while(!q.empty())
        {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int t = q.front().second;
            time = max(time,t);
            q.pop();
            for(int i = 0 ; i < 4 ; i++)
            {
                int nRow = row + delRow[i];
                int nCol = col + delCol[i];

                if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && grid[nRow][nCol] == 'E' && vis[nRow][nCol] != 2)
                {
                    vis[nRow][nCol] = 2;
                    q.push({{nRow,nCol},t+1});
                }
            }

            
        }
        for(int i = 0 ; i < n ; i++)
        {
            for(int  j = 0 ; j < m ; j++)
            {
                if(vis[i][j] != 2 && grid[i][j] == 'E')
                {
                    return -1;
                }
            }
        }
        return time;
    }
};
int main(){
    int n, m;
    cout << "Enter number of rows and columns: ";
    cin >> n >> m;

    vector<vector<char>> grid(n, vector<char>(m));

    cout << "Enter the character grid values ('*': 0, 'E': 1, 'A': 2):\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
        }
    }

    solution s;
    int result = s.solve(grid);  // This should accept a char grid now
    cout << "Minimum time to rot all oranges: " << result << endl;

    return 0;solution sol;

}