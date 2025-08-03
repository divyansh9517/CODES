#include<iostream>
#include<vector>
using namespace std;

int solve(int n)
{
    int ans = (n*n)/4 +1;
    return ans;
}


int main(){
    int t ;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;

        cout<<solve(n)<<endl;
    }
    return 0;
}