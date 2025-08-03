#include<bits/stdc++.h>

using namespace std;

void solve(vector<int> &arr,int n)
{
    vector<int> ans(n,0);
    for(int i = 0 ;i < n ; i++)
    {
        int sum = 0; 
        for(int j = i; j < n;j++)
        {
            sum+=arr[j];
            if(sum > 0)
            {
                ans[i] = j - i +1;
                break;
            }
        }
    }

    for(int i = 0 ; i < n ; i++)
    {
        cout<<ans[i]<<" ";
    }
    
}

// // code optimization


// void solve(vector<int> &arr, int n) {
//     vector<int> ans(n, 0);
//     vector<int> prefix(n+1, 0);

    
//     for (int i = 0; i < n; i++) {
//         prefix[i+1] = prefix[i] + arr[i];
//     }

    
//     for (int i = n - 1; i >= 0; i--) {
//         if (prefix[n] - prefix[i] > 0) 
//         { 
//             ans[i] = n - i;
//         } 
//         else if (arr[i] > 0) 
//         {
//             ans[i] = 1;
//         }
//         else if (i < n - 1 && ans[i+1] > 0) 
//         {
//             ans[i] = ans[i+1] + 1;
//         } 
//         else 
//         {
//             ans[i] = 0;
//         }
//     }

//     for (int i = 0; i < n; i++) {
//         cout << ans[i] << " ";
//     }
// }

// int main() {
//     vector<int> arr = {-4, 3, 4};
//     int n = arr.size();
//     solve(arr, n);
// }


int main() {
    vector<int> arr = {-4, 3, 4};
    int n = arr.size();
    solve(arr, n);
}