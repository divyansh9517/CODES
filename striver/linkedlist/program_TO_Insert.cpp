#include<bits/stdc++.h>

using namespace std;

class Node
{
    public:

    int data;
    Node* next ;
    Node(int val)
    {
        this->data = val;
        this->next = NULL;
    }
};

Node* create(Node* head,int x)
{
    Node* newNode = new Node(x);
    if(head == NULL)
    {
        return newNode;
    }
    // insertion at tail
    Node * temp = head;
    while(temp->next != NULL)
    {
        temp=temp->next;
    }
    temp->next = newNode;
    //temp->next = NULL;
    return head;
}

void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main()
{
    Node* head = NULL;
    head = create(head,9);
    head = create(head,8);
    head = create(head,0);
    head = create(head,3);
    head = create(head,4);
    head = create(head,5);

    printList(head);


}