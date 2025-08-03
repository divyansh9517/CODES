#include<bits/stdc++.h>
using namespace std;

int sum(int n1,int n2,int n3 = 0,int n4 = 0);

int main(){
    int s1,s2,s3;
    s1 = sum(10,20);
    s2 = sum(10,20,30);
    s3 = sum(10,20,30,40);
    cout<<s1<<" "<<s2<<" "<<s3<<" ";
    return 0;
}

int sum(int n1,int n2,int n3,int n4){
    return(n1+n2+n3+n4);
}