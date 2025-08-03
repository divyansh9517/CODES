#include<bits/stdc++.h>
using namespace std;

int toggleBit(int n , int i){
    return (n ^ (1<<i));
}
int main(){
    int n = 13;
    int i = 2;
    cout<<toggleBit(n,i)<<" ";
    return 0;
}