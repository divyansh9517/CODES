#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxlen = 1;
    int start = 0;

    bool solve(string &s, int i, int j) {
        if (i >= j)
            return true;

        bool flag = false;
        if (s[i] == s[j]) {
            flag = solve(s, i + 1, j - 1);
        }

        if (flag) {
            int currlen = j - i + 1;
            if (currlen > maxlen) {
                maxlen = currlen;
                start = i;
            }
        }
        return flag;
    }

    string longestPalindrome(string &s) {
        int n = s.length();
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                solve(s, i, j);
            }
        }
        return s.substr(start, maxlen);
    }
};

int main() {
    string s = "babda";
    Solution sol;
    string result = sol.longestPalindrome(s);
    cout << "Longest Palindromic Substring: " << result << endl;
    return 0;
}
