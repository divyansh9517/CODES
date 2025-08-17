#include<bits/stdc++.h>
using namespace std;
 

bool primeCheck(int n){
    bool flag = true;
    if(n == 0 || n == 1){
        flag = false;
    }

    for(int i = 2 ; i * i <= n ; i++){
        if(n % i == 0){
            flag = false;
            break;
        }
    }
    return flag;
}
// TC -> O(sqrt(n)*2*sqrt(n))
// int main(){
//     int n = 780;
//     vector<int> ans;
//     for(int i = 2 ; i <= sqrt(n) ; i++){
//         if(n % i == 0){
//             if(primeCheck(i)){
//                 ans.push_back(i);
//             }
//             if(n % i != i){
//                 if(primeCheck(n/i))ans.push_back(n/i);
//             }
//         }
//     }

    // for(int i : ans){
    //     cout<<i<<" ";
    // }
// }


// TC -> O(N)
int main(){

    int n = 780;
    vector<int>  ans;
    for(int i = 2 ; i*i <= n ;i++){
        if(n%i == 0){
            ans.push_back(i);
            while(n%i == 0){
                n = n/i;
            }
        }
    }
    if(n != 1)ans.push_back(n);

    for(int i : ans)
    {
        cout<<i<<" ";
    }
    return 0;
}