#include<bits/stdc++.h>
using namespace std;

int cntStBt(int n){
    int cnt = 0 ; 
    // while(n > 0)
    // {
    //     cnt += n & 1 ;
    //     n = n  >> 1;
    // }
    // if(n == 1 )cnt += 1;
    while(n != 0){
        n = n&(n-1);
        cnt++;
    }
    return  cnt;
}
int main(){
    int  n = 13;
    cout<<cntStBt(n);
    return 0;
}