#include<bits/stdc++.h>
using namespace std;

string reverseString(string &s)
{
    int i = 0 ;
    int j = s.length()-1;
    //string temp;
    while(i <= j)
    {
        swap(s[i],s[j]);
        i++;
        j--;
    }
    string ans = s;
 return ans;   
}

void palindrome(string s)
{
    string a = s;
    
    string t = reverseString(s);

    if( a== t)
    {
        cout<<"palindrome";
    }
    else{
        cout<<"not a palindorme";
    }
}

int main()
{
    string s = "abba";
    palindrome(s);

    
    return 0;

}