#include<bits/stdc++.h>
using namespace std;

class Cque{
    public :
    int * arr;
    int size;
    int front;
    int rear;

    Cque(int size)
    {
        this->size = size;
        front = -1;
        rear = -1;
        arr = new int[size];
    }

    void push(int x)
    {
        //step 1 for overflow
        if((front  == 0 && rear == size-1) || rear == front-1  )
        {
            cout<<"overflow";
        }
        // step 2  for starting 
        if(front == -1 && rear == -1)
        {
            front++;
            rear++;
            arr[rear] = x;
        }
        //step 3 circular nature
        else if(rear == size-1 && front != 0)
        {
            rear = 0 ;
            arr[rear] = x;
        }
        //step 4 anything 
        else{
            rear++;
            arr[rear] = x;
        }
    }

    void pop(){
        if(front == -1 && rear == -1)
        {
            cout<<"Underflow";
        }
        else if(front == rear)
        {
            arr[front] = -1;
            front--;
            rear--;
        }
        else if(front == size-1)
        {
            arr[front]= -1;
            front=0;
        }
        else{
            arr[front]=-1;
            front++;
        }
    }
    void print()
    {
        for(int i = 0 ; i < size; i ++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }


};
int main(){
    Cque c(5);
    c.push(2);
    c.print();
    c.push(6);
    c.print();
    c.push(5);
    c.print();
    c.push(8);
    c.print();
    c.push(10);
    c.print();
    c.pop();
    c.print();

    c.push(11);
    c.print();
}