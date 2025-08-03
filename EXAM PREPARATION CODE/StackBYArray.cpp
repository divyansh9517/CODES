#include <bits/stdc++.h>
using namespace std;

class Mystack {
    int top;
    int size;
    int* arr;

public:
    Mystack() {
        top = -1;
        size = 1000;
        arr = new int[size];
    }

    ~Mystack() {
        delete[] arr;
    }

    void push(int x) {
        if (top >= size - 1) {
            cout << "Stack Overflow" << endl;
            return;
        }
        top++;
        arr[top] = x;
    }

    int pop() {
        if (top < 0) {
            cout << "Stack Underflow" << endl;
            return -1;
        }
        int x = arr[top];
        top--;
        return x; 
    }

    int peek() { 
        if (top < 0) {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return arr[top];
    }

    int getSize() { 
        return top + 1;
    }

    void print() {
        if (top < 0) {
            cout << "Nothing to print" << endl;
            return;
        }
        for (int i = 0; i <= top; i++) {  // Fix: Changed i < top to i <= top
            cout << arr[i] << endl;
        }
    }
};

int main() {
    Mystack s;
    s.push(5);
    s.push(6);
    s.push(2);

    cout << "Stack elements:" << endl;
    s.print();

    cout << "Top element: " << s.peek() << endl;

    s.pop();
    cout << "After pop operation:" << endl;
    s.print();

    cout << "Stack size: " << s.getSize() << endl;

    return 0;  // Fix: Added return statement
}
