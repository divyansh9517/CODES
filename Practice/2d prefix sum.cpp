#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<vector<int>> mat = {{1,2,3},{4,5,6},{7,8,9}};
    vector<vector<int>> pref(mat.size(),vector<int>(mat[0].size()));

    // copy kr rahey hai hai
    for(int i = 0; i < mat.size() ;i++ )
    {
        for(int j = 0 ; j < mat[0].size() ; j++)
        {
            pref[i][j] = mat[i][j];
        }
    }

    

    // Row-wise prefix sum
    for(int i = 0; i < mat.size(); i++)
    {
        for(int j = 1; j < mat[0].size(); j++)
        {
            pref[i][j] += pref[i][j-1];
        }
    }

    cout<<"row wise printing  : - "<<endl;
    for(int i = 0; i < pref.size() ;i++ )
    {
        for(int j = 0 ; j < pref[0].size() ; j++)
        {
            cout<<pref[i][j]<<" ";
        }
        cout<<endl;
    }


    
    // Column-wise prefix sum
    for(int j = 0; j < mat[0].size(); j++)
    {
        for(int i = 1; i < mat.size(); i++)
        {
            pref[i][j] += pref[i-1][j];
        }
    }

    cout<<"column wise : - "<<endl;
    // Printing
    for(int i = 0; i < pref.size() ;i++ )
    {
        for(int j = 0 ; j < pref[0].size() ; j++)
        {
            cout<<pref[i][j]<<" ";
        }
        cout<<endl;
    }



    // higher  altitude 
    int maxi = 0 ;
    for(int  i= 0 ; i < pref.size() ; i++)
    {
        for(int j = 0;j < pref[0].size() ;j++)
        {
            if(pref[i][j] > maxi )
            {
                maxi = pref[i][j];
            }
        }
    }

    cout<<"printing the  maximum altitude : - "<< maxi ;
}

