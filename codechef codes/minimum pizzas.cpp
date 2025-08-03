#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
	    int n,x;
	    cin>>n>>x;
	    
	    if((n*x) % 4 == 1)
	    {
	        int ans =((x*n)/4) +1;
	        cout<<ans<<endl;
	    }
	    else
	    {
	        int ans = (x*n)/4;
	        cout<<ans<<endl;
	    }
	    
	}
	return 0;

}