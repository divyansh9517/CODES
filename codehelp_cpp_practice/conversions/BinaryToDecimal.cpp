#include<iostream>
#include<math.h>
using namespace std;

int BinaryToDecimal(int n)
{
    int decimal = 0;
    int i= 0;
    while(n >0)
    {
        int bits = n % 10;
        decimal += bits*pow(2,i++);
        n /= 10;
    }
    return decimal;
}

int main()
{
    int n = 10111;
    cout<<BinaryToDecimal(n);
    return 0;
}