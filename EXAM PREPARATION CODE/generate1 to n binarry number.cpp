#include<bits/stdc++.h>
using namespace std;
 
void generate(int n)
{
    queue<string> q;
    q.push("1");

    while(n--)
    {
        string s1 = q.front();
        q.pop();
        cout<< s1 << "\n";

        string s2 = s1;

        q.push(s1.append("0"));
        q.push(s2.append("1"));


    }

}
int main(){
    int n = 10;
    generate(n);
    return 0;
}