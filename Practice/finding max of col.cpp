#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<vector<int>> mat{ 
        {4, 5, 3},
        {2, 3, 2},
        {1, 2, 7}
    };

    vector<int> ans;
    int maxi = 0; 
    for (int j = 0; j < mat[0].size(); j++) 
    {
        for (int i = 0; i < mat.size(); i++) 
        {
            if (maxi < mat[i][j]) 
            {
                maxi = mat[i][j];
            }
            
        }
        ans.push_back(maxi);
    }
    for(int i = 0  ; i < ans.size(); i++)
    {
        cout<< "element in column "<<i << " is : - "<<ans[i]<<" "<<endl;
    }

    return 0;
}
