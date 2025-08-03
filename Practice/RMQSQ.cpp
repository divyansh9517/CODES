#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007;
#define int long long
const int N = 100000+10;
int n, q, v[N] ,root,bucket[N] , l,r;

signed main(){
    // now taking the size of array
    cin>>n;
    // finding squrt 
    root = sqrt(n);
    for(int i = 0 ; i < n  ;i++)
    {
        cin>>v[i];
    }
    for(int i = 0 ; i < n ;i++)
    {
        if(i%root == 0)
        {
            bucket[i/root] = v[i];
        }
        else{
            bucket[i/root] = min(bucket[i/root],v[i]);
        }
    }
    // no. of queries
    cin>>q;
    for(int i = 0 ; i < q ; i++)
    {
        cin>>l >> r;
        int ans = 1e9;
        for(int j = l ; j <=r ; j++)
        {
            if(j%root == 0 && j+root-1 <= r)
            {
                ans = min(ans,bucket[j/root]);
                j+=root-1;
            }
            else{
                ans = min(ans,v[j]);
            }

        }
        cout<<ans<<endl;
    }
}