#include<iostream>
using  namespace  std;;

int main()
{
    int a = 5;
    cout<<"Normal  variable "<<a<<endl;

    int &temp = a;
    temp++;
    cout<<"Reference Variable "<<a<<endl;
    
}