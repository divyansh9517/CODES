#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data)
    {
        this->data=data;
        this->next = nullptr;
    }
    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }

};
void print(Node* head)
{
    Node* temp = head;
    while(temp != nullptr)
    {
        cout<<temp->data<<"->";
        temp = temp->next;
    }
}

Node* insert(Node* head,int val)
{
    Node * temp = new Node(val,head);
    return temp;
}

void reverseOfLinkedList(Node* head)
{
    Node* temp = head;

    stack<int> s;

    while(temp != nullptr)
    {
        s.push(temp->data);
        temp = temp->next;
    }

    while(!s.empty())
    {
        cout << s.top();
        s.pop();
        if (!s.empty()) {
            cout << "->";
        }
        cout<<endl;
    }
}
Node* deletetion(Node* head)
{
    if(head == NULL || head->next == NULL)
    {
        return 0;
    }

    Node*  temp = head;
    while(temp->next->next != NULL)
    {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = NULL;
    return head;
}
Node* deleteFormHead(Node* head)
{
    if(head == nullptr)
    {
        return nullptr;
    }
    Node* temp = head;
    head = head->next;
    delete temp;
    return head;
}
Node* insertAtTail(Node* head,int val)
{
    Node* newNode = new Node(val);
    if(head == NULL)
    {
        return newNode;
    }
    Node*temp = head;
    while(temp->next != nullptr)
    {
        temp= temp->next;
    }
    temp->next = newNode;
   
   
    return head;
}

Node* midle(Node* head)
{
    Node* slow = head;
    Node* fast = head;

    while(fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}
Node* removeFrom(Node* head,int n) // it is from end
{
    Node* dummy = new Node(0);
    dummy->next = head;
    Node* first = dummy;
    Node* second = dummy;

    for(int i = 0 ; i <= n ; i++)
    {
        first = first->next;
    }

    while(first!=NULL)
    {
        first = first->next;
        second = second->next;
    }
    second->next = second->next->next;
    return dummy->next;
}
int main()
{
    Node* head = new Node(5);
    head->next = new Node(6);
    head->next->next = new Node(7);
    head->next->next->next = new Node(8);
    head->next->next->next->next = new Node(9);

    print(head);
    head = insert(head,100); // insert at head;
    cout<<"New linked list"<<endl;
    print(head);
    cout<<endl;
    reverseOfLinkedList(head); // reverse linked list
    cout<<endl;
    deletetion(head); //deletion from tail
    print(head);
    head = deleteFormHead(head); // deletion from head
    cout<<endl;
    print(head);
    head = insertAtTail(head,10);
    cout<<endl;
    print(head);
    cout<<""<<endl;
    Node* miidd = midle(head);
    cout<<miidd->data<<endl;
    removeFrom(head,1);
    cout<<endl;
    print(head);
    return 0;

}