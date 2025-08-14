
#include<bits/stdc++.h>
using namespace std;

void maxHeap(){
    priority_queue<int> mh;
    mh.push(10);
    mh.push(20);
    mh.push(5);
    mh.push(30);
    mh.push(15);
    while(!mh.empty()){
        cout<<mh.top()<<" ";
        mh.pop();
    }
}
void minHeap(){
    priority_queue<int,vector<int> ,greater<int>> mh;
    mh.push(10);
    mh.push(20);
    mh.push(5);
    mh.push(30);
    mh.push(15);
    while(!mh.empty()){
        cout<<mh.top()<<" ";
        mh.pop();
    }
}

int main(){
    cout<<"Max Heap: ";
    maxHeap();
    cout<<"\nMin Heap: ";
    minHeap();
    cout<<"\n";
    return 0;
}