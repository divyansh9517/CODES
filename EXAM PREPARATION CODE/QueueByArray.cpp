#include<bits/stdc++.h>
using namespace std;

class Myqueue{
    public :

    int *arr;
    int size;
    int front;
    int rear;

    Myqueue(int size)
    {
        arr = new int[size];
        this->size=size;
        front = -1;
        rear = -1;
    }

    void push(int x)
    {
        if(rear == size-1)
        {
            cout<<"Overflow"<<endl;
        }
        if(front == -1 && rear == -1)
        {
            front++;
            rear++;
            arr[rear] = x;
        }
        else{
            rear++;
            arr[rear] = x;
        }
    }
    void pop(){
        if(front == -1  && rear == -1)
        {
            cout<<"Underflow"<<endl;
            return ;
        }
        else if(front == rear)
        {
            arr[rear] = -1;
            front = -1;
            rear = -1;
        }
        else{
            arr[front] = -1;
            front++;
        }
    }

    bool isEmpty()
    {
        if(front == -1 && rear == -1)
        {
            return true;
        }
        else{
            return false;
        }
    }
    int getSize(){
        if(front == -1 && rear == -1)
        {
            return 0;
        }
        else{
            return rear-front+1;
        }
    }
    void print(){
        for(int i = 0 ;  i  < size ; i++)
        {
            cout<<arr[i]<<" , ";
        }
        cout<<endl;
    }
};
int main()
{
    Myqueue q(5);
    q.push(5);
    q.push(6);
    q.push(7);
    q.push(8);
    q.push(10);
    q.print();
    q.pop();
    q.print();
    cout<<q.getSize();

}