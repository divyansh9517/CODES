#include<bits/stdc++.h>

using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int val)
    {
        this->data = val;
        this->next = nullptr;
    }
};

void deleteNode(Node*& head)  // Pass by reference
{
    if (head == nullptr)
        return;

    Node* temp = head;
    head = head->next;
    delete temp;

    Node* current = head;
    while (current)
    {
        cout << current->data << "->";
        current = current->next;
    }
    cout << "NULL" << endl;
}

void deleteFromLast(Node* head)
{
    if (head == NULL) {
        cout << "List is empty." << endl;
        return;
    }

    if (head->next == NULL) {
        // Only one node in the list
        delete head;
        head = NULL;
        cout << "List is now empty." << endl;
        return;
    }

    Node* temp = head;
    
    // Traverse to the second last node
    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    // Delete the last node
    delete temp->next;
    temp->next = NULL;

    // Print remaining list
    Node* curr = head;
    while (curr) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

void convertLLtoArray(Node* head)
{
    Node* temp = head;
    vector<int> ans;
    while(temp != nullptr)
    {
        ans.push_back(temp->data);
        temp = temp->next;
    }

    for(int i = 0 ; i < ans.size() ; i++)
    {
        cout<<ans[i]<<" ";
    }

}

int main(){
    Node* head = new Node(2);
    head ->next = new Node(3);
    head->next->next = new Node(4);
    head->next->next->next = new Node(5);
    convertLLtoArray(head);
    cout<<endl;
    deleteNode(head);
    cout<<endl;
    deleteFromLast(head);
}

