#include<bits/stdc++.h>

using namespace std;

class Node{
    public :
    int data;
    Node* next;

    Node(int val)
    {
        this->data = val;
        this->next = NULL;
    }
};

int create(int data)
{
    Node* x = new Node(data);
    return x->data;
}
int main()
{
    int s = 5;
    cout<<create(s);
}
    
    
