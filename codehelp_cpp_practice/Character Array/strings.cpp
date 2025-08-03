#include<bits/stdc++.h>
using namespace std;

// string are used for storing text . a string variable contains a collection of characters surrounded by double quotes

int main()
{
    // declare 
    string name;
    name.push_back('a');
    name.push_back('b');
    name.push_back('c');

    cout<<name<<endl;
    //initialization

    // string null character ko apney aap daal deti hai as a terminator
    string a = "My name is love Babbar";
    string b = "Lover";
    int ans = a.find(b);
    if(ans == string::npos) // npos -> no position
    {
        cout<<"b string not found in a string "<<endl;
    }
    else{
        cout<<" Found "<<endl;
    }

    string surName = "Saxena";

    cout<<surName.length()<<endl;
    cout<<surName<<endl;

    string str = "babbar";
    string temp ="love";
    if(str.compare(temp) == 0)
    {
        cout<<"Strings are equal "<<endl;
    }
    else{
        cout<<"string are not equals"<<endl;
    }
    str.insert(0,temp);
    cout<<str<<endl;

    temp.append(str);

    

    //cout<<temp<<endl;
    return 0;
}