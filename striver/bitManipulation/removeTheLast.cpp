#include<bits/stdc++.h>
using namespace std;

int removeTheLast(int n){
    return (n&(n-1));
}

int main(){
    int n = 16;
    cout<<removeTheLast(n)<<" ";
    return 0;
}