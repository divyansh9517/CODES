#include<bits/stdc++.h>
using namespace std;

bool powerof(int n)
{
    return (n&(n-1) == 0);
}
int main(){
    int n = 16;
    if(powerof(n)){
        cout<<"Yes"<<" ";
    }
    else {
        cout<<"No"<<" ";
    }
    return 0;
}