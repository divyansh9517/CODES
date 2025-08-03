#include <bits/stdc++.h>
using namespace std;

string solve(int n, vector<int> &arr)
{
    int oneGm = 0;
    int twoGm = 0;

    int sum =0 ;
    for(int weight : arr)
    {
        if(weight == 1)
        {
            oneGm++;
        }
        else if(weight == 2)
        {
            twoGm++;
        }

        sum += weight;
    }

    if(sum %2 != 0)return "NO";

    int half = sum/2;

    if(half%2 == 0)
    {
        return "YES";
    }
    else{
        if(oneGm >= 1)
        {
            return "YES";
        }
        else{
            return "NO";
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) 
    
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cout << solve(n, arr) << endl;
    }
    return 0;
}