#include<iostream>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int a,b;
        int c,d;

        cin>>a>>b;
        cin>>c>>d;

        if(a <= c && b <=  d)
        {
            cout<<"Possible"<<endl;
        }
        else{
            cout<<"Impossible"<<endl;
        }
    }
    return 0;
    
}