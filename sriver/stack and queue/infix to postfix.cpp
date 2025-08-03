#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    
        // Function to return priority of operators
        int priority(char ch) {
            if (ch == '^') {
                return 3;
            }
            if (ch == '*' || ch == '/') {
                return 2;
            }
            if (ch == '+' || ch == '-') {
                return 1;
            }
            return 0; 
        }
    
        string infixToPostfix(string& s) {
            stack<char> st; 
            string ans = "";
            int n = s.size();
            int i = 0;
    
            while (i < n) {
                
                if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9')) {
                    ans += s[i];
                }
                
                else if (s[i] == '(') {
                    st.push(s[i]);
                }
                
                else if (s[i] == ')') {
                    while (!st.empty() && st.top() != '(') {
                        ans += st.top();
                        st.pop();
                    }
                    if (!st.empty()) {
                        st.pop(); 
                    }
                }
              
                else {
                    while (!st.empty() && priority(s[i]) <= priority(st.top()) && st.top() != '(') {
                        ans += st.top();
                        st.pop();
                    }
                    st.push(s[i]);
                }
                i++;
            }
    
            while (!st.empty()) {
                ans += st.top();
                st.pop();
            }
    
            return ans;
        }
    };

    int main() {
        string se= "a+b*(c^d-e)";
        Solution obj;
        cout << obj.infixToPostfix(se);
        return 0;
    }