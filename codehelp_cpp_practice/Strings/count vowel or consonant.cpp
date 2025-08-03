#include<iostream>
using namespace std;

void check(string s)
{
    int vowel = 0;
    int conso = 0;
    for(int i = 0  ; i < s.length() ;i++)
    {
        if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o'|| s[i]=='u')
        {
            vowel++;
        }
        else{
            conso++;
        }
    }
    cout<<"Vowels : - "<<vowel<<endl;
    cout<<"Consonant : - "<<conso<<endl;
}
int main(){
    string s = "abbcbd";
    check(s);
    return 0;
}