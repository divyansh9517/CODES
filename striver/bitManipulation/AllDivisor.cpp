#include<bits/stdc++.h>
using namespace std;

int main(){
    int n = 36;
    vector<int> ans;
    for(int i = 1 ; i*i <= n ; i++){
        if(n % i == 0){
            ans.push_back(i);
            if(n % i != i){
                ans.push_back(n/i);
            }
        }
    }

    for(int i = 0 ; i < ans.size() ; i++){
        if(ans[i] == ans[i+1]){
            continue;
        }
        cout<<ans[i]<<" ";
    }
    return 0;
}