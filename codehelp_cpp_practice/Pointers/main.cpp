#include<iostream>
using namespace std;
int main(){
    int num = 50;
    int *ptr = &num;
    cout<<num<<endl;
    cout<<ptr<<endl;
    cout<<&ptr<<endl;
    cout<<*ptr<<endl;
    (*ptr)++;
    cout<<*ptr<<endl;
    //cout<<*ptr<<endl;
}