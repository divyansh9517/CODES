#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &arr)
{
    // vector<int> dp(arr.size()+1,0);

    // // if(i >= arr.size())
    // // {
    // //     return 0;
    // // }
    // // if(dp[i] != -1)
    // // {
    // //     return dp[i];
    // // }
    // for(int i = arr.size()-2 ; i >= 0; i--)
    // {
    //     int include = dp[i] + dp[i-2];
    //     int exclude = 0 + dp[i-1];

    //     dp[i] = max(include,exclude);
    // }

    // // int include = arr[i] + solve(i+2,arr,dp);
    // // int exclude = 0+solve(i+1,arr,dp);
#include<bits/stdc++.h>
using namespace std;

int main(){

    int n ;
    cin>>n;
    vector<int> arr(n);
    for(int i  = 0 ; i < n ; i++)
    {
        cin>>arr[i];
    }

    //third test case failed on this 

    // sort(arr.begin(),arr.end());
    // reverse(arr.begin(),arr.end());

    // int sarrja = 0;
    // int dima = 0;
    // for(int i = 0 ; i < n ; i++)
    // {
    //     if(i &1)
    //     {
    //         dima += arr[i];
    //     }
    //     else{
    //         sarrja += arr[i];   
    //     }
        
    // }
    
    // without sorting
    int leftIdx = 0; 
    int rightIdx = n-1;
    int serrja = 0;
    int dima = 0;
    int pick = 0;

    while(leftIdx <= rightIdx)
    {
        int chance = 0;
        if(arr[leftIdx]>= arr[rightIdx])
        {
            pick = arr[leftIdx];
            leftIdx++;
        }
        else
        {
            pick = arr[rightIdx];
            rightIdx--;
        }

        if(chance % 2 == 0)
        {
            serrja += pick;
        }
        else
        {
            dima += pick;
        }
        chance++;
    }
    cout<<serrja<<" "<<dima<<endl;
    return 0;

}
    
    // return dp[0];

    int n = arr.size();
    if (n == 0) return 0;
    if (n == 1) return arr[0];

    vector<int> dp(n, 0);
    dp[0] = arr[0];
    dp[1] = max(arr[0], arr[1]);

    for (int i = 2; i < n; i++)
    {
        int include = arr[i] + dp[i - 2];
        int exclude = dp[i - 1];
        dp[i] = max(include, exclude);
    }

    return dp[n - 1];
}

int main(){
    vector<int> arr = {2,4,3,5,6};
    int i = 0;
    vector<int> dp(arr.size(),-1);
    cout<<solve(arr);
    return 0;
}