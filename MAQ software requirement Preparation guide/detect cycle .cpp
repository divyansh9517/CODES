#include<bits/stdc++.h>


using namespace std;

class Node{
    public :
    int data;
    Node* next;

    Node(int data)
    {
        this->data  = data;
        this->next = NULL;
    }

};

bool checkCycle(Node* head) {
    Node* fast = head;
    Node* slow = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            return true;
        }
    }
    return false;
}

int main() {
    Node* node1 = new Node(3);
    Node* node2 = new Node(2);
    Node* node3 = new Node(0);
    Node* node4 = new Node(-4);

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node2; // cycle here

    if (checkCycle(node1)) {
        cout << "Cycle detected!" << endl;
    } else {
        cout << "No cycle detected." << endl;
    }

    return 0;
}