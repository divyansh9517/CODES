#include <bits/stdc++.h>
using namespace std;

bool isOperand(char x) {
    return (x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z');
}

string prefixToInfix(string s) {
    stack<string> st;

    for (char ch : s) {
        if (isOperand(ch)) {
            string op(1, ch);
            st.push(op);
        } else {
            string op1 = st.top(); st.pop();
            string op2 = st.top(); st.pop();
            string exp = "(" + op1 + ch + op2 + ")";
            st.push(exp);
        }
    }

    return st.top();
}

int main() {
    string s = "ab*c+";
    cout << prefixToInfix(s);
    return 0;
}