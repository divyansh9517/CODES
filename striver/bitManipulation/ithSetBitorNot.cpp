#include<bits/stdc++.h>
using namespace std;

bool check(int n,int i){
    if((n&(1<<i)) != 0)return true;
    return false;
}
int main(){
    int n = 13;
    int i = 2;
    if(check(n,i)){
        cout<<"1";
    }
    else {
        cout<<"0";
    }
    return 0;
}