#include<bits/stdc++.h>
using namespace std;

void reverseString(string &s)
{
    int i = 0 ;
    int j = s.length()-1;

    while(i <= j)
    {
        swap(s[i],s[j]);
        i++;
        j--;
    }
}
int main(){
    string s = "abdac";
    reverseString(s);

    cout<<s<<endl;
}