#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

bool checkCircular(Node* head) {
    if (head == NULL) return false;
    Node* slow = head;
    Node* fast = head;
    
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        
        if (slow == fast) {
            return true;
        }
    }
    return false;
}

void Searching(Node* head, int target) {
    if (head == NULL) {
        cout << "List is empty" << endl;
        return;
    }

    if (checkCircular(head)) {
        Node* temp = head;
        do {
            if (temp->data == target) {
                cout << "Search successful" << endl;
                return;
            }
            temp = temp->next;
        } while (temp != head);

        cout << "Target not found in the list" << endl;
    } else {
        cout << "The list is not circular" << endl;
    }
}

int main() {
    Node* head = new Node(5);
    head->next = new Node(7);
    head->next->next = new Node(9);
    head->next->next->next = new Node(6);
    head->next->next->next->next = head;

    Searching(head, 6);
    
    return 0;
}
