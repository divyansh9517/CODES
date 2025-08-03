#include<iostream>
using namespace std;

void printCounting(); // declaration


int sum(int a,int b) //  declaration + definition
{
    int totalSum = a+b;
    return totalSum;
}

int getMultiply(int x,int y,int z)
{
    int result = x*y*z;
    return result;
}


int convertIntoCelsius(int far)
{
    int cel = (far-32)*5/9;
    return cel;
}

char convertToUpperCase(char ch)
{
    char  ans = ch - 'a'+'A';
    return ans;
}

int main(){
   
    int ans =sum(5,10);
    cout<<ans<<endl;
    printCounting();


    cout<<"Multiply : - "<<getMultiply(2,4,5)<<endl;

    cout<<"Convert Into Celsius : - "<<convertIntoCelsius(32)<<endl;

    cout<<"Convert to Upper case : - "<<convertToUpperCase('b')<<endl;
    // printCounting();
    // cout<<"Babbar bhaiya"<<endl;
    // printCounting();
    
}

void printCounting() // definition
{
    for(int i =1 ; i <= 5  ;i++)
    {
        cout<<i<<" ";
    }
    cout<<endl;
}