#include<bits/stdc++.h>
using namespace std;


class Node{
    public : 
    int data;
    Node* next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

int middleElement(Node* head)
{
    Node* fast = head;
    Node* slow = head;

    while(fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow->data;
}
int main(){
    Node* head = new Node(5);
    head->next = new Node(6);
    head->next->next = new Node(8);
    head->next->next->next = new Node(7);
    head->next->next->next->next = new Node(10);
    cout<<middleElement(head);

}