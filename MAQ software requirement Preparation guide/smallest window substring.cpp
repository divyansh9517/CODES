#include<bits/stdc++.h>

using namespace std;
string solve(string s1, string s2)
{
    vector<int> mapp(256,0);

    for(int i = 0 ; i < s2.size() ; i++)
    {
        mapp[s2[i]]++;
    }

    int minLen = INT_MAX;
    int left = 0 ; 
    int right = 0 ;
    int count = 0;
    int sIndex = -1;
    while(right < s1.size())
    {
        if(mapp[s1[right]] > 0)
        {
            count++;
        }
        mapp[s1[right]]--;


        while(count == s2.size())
        {
            if(right-left+1 < minLen)
            {
                minLen = right - left + 1;
                sIndex = left;
            }
            mapp[s1[left]]++;
            if(mapp[s1[left]]>0){
                count --;
            }
            left++;
        }
        right++;
    }
    return sIndex == -1 ? "":s1.substr(sIndex,minLen);
}

int main(){
    string s1 = "ADOBECODEBANC";

    string s2 = "ABC";

    cout<<solve(s1,s2);
}