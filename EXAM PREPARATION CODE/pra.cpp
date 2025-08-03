#include<bits/stdc++.h>
using namespace std ;

class solution{

    public :
    int maxLen = 0;
    int start = 0;

    bool solve(string &s ,int i ,int j)
    {
        if(i >= j)
        {
            return true;
        }

        bool flag = false;

        if(s[i] == s[j])
        {
            flag = solve(s,i+1,j-1);
        }
        if(flag)
        {
            int currLen = j - i + 1;
            if(currLen > maxLen)
            {
                maxLen = currLen;
                start = i;
            }
        }
        return flag;
    }

    string LPs(string &s)
    {
        int n = s.length();

        for(int i = 0 ; i < n ; i++)
        {
            for(int j = i ; j < n ; j++){
                solve(s,i,j);
            }
        }
        return s.substr(start,maxLen);
    }

}