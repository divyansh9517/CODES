#include<bits/stdc++.h>
using namespace std;
class Node{
    public :
    int data;
    Node* next ; 
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};
class MyQueue{
    private:
    Node* front ;
    Node* rear;
    int size;
    public:
    MyQueue(){
        front= NULL;
        rear = NULL;
        size = 0;
    }

    void push(int x)
    {
        Node* newNode = new Node(x);
        if(rear == NULL)
        {
            front = rear = newNode;
        }
        else{
            rear->next = newNode;
            rear = newNode;
        }
        size++;
    }

    void pop(){
        if(front == nullptr)
        {
            cout<<"Underflow";
            return;
        }
        Node* temp = front;
        front = front->next;
        if(front == NULL)
        {
            rear = NULL;
        }
        delete temp;
        size--;
    }

    bool isEmpty(){
        return front == NULL;
    }
    int getSize(){
        return size;
    }
    void print(){
        if(front == NULL)
        {
            cout<<"Queue is empty"<<endl;
        }
        Node* temp = front;
        while(temp !=  NULL)
        {
            cout<<temp->data<<"->";
            temp = temp->next;
        }
        cout<<"NULL"<<endl;
    }
};

int main() {
    MyQueue q;
    q.push(10);
    q.push(20);
    q.push(30);

    cout << "Queue elements:" << endl;
    q.print();

    cout << "Queue size: " << q.getSize() << endl;

    q.pop();
    cout << "After one pop operation:" << endl;
    q.print();

    cout << "Queue size: " << q.getSize() << endl;

    return 0;
}
