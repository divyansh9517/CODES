#include<bits/stdc++.h>
using namespace std;

int clearBit(int n , int i){
    int ans = n&(~(1<<i));
    return ans;
}
int main(){
    int n = 13;
    int i = 2;
    cout<<clearBit(n,i)<<" ";
    return 0;
}