#include<bits/stdc++.h>
using namespace std;

int solve(string x){
    int len = x.length() , po = 1 ,num =0;
    for(int i = len -1 ; i >=0 ;i--){
        if(x[i] == '1'){
            num = num + po;
        }
        po = po *2;
    }
    return num;
}

int main(){
    string x = "1101";
    int ans = solve(x);
    cout<<ans<<" ";
    return 0;
}