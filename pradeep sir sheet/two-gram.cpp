#include<bits/stdc++.h>
using namespace std;

string solve(int n , string &s)
{
    unordered_map<string,int> mapp;
    int maxFreq = 0;
    string ans = "";

    for(int i = 0 ; i <  n ;  i++)
    {
        string twoGram = s.substr(i,2);
        mapp[twoGram]++;
        if(mapp[twoGram] > maxFreq)
        {
            maxFreq = mapp[twoGram];
            ans = twoGram;
        }
    }
    return ans;

}
int main(){
    int n ;
    cin>>n;
    string s ;
    cin>>s;
    cout<<solve(n,s)<<endl;
    
}