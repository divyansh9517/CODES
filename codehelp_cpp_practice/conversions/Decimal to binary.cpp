#include<bits/stdc++.h>
using namespace std;

//method 1
int  decimalToBinary(int n)
{
    int binaryNo = 0;
    int i = 0;
    while(n > 0)
    {
        int bits = n % 2;
        binaryNo = bits*pow(10,i)+binaryNo;
        //cout<<bits<<endl;
        n = n/2;
        i++;
    }
    return binaryNo;
}

// method 2 
int  decimalToBinary2(int n)
{
    int binaryNo = 0;
    int i = 0;
    while(n > 0)
    {
        int bits = n&1;
        binaryNo = bits*pow(10,i)+binaryNo;
        //cout<<bits<<endl;
        n = n>>1;
        i++;
    }
    return binaryNo;
}


int main(){
    int n = 10;
    cout<<decimalToBinary(n);
    return 0;
}