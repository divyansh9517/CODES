#include<bits/stdc++.h>
using namespace std;

struct  Maxheap{
    vector<int> heap;
    int parent(int i){
        return (i-1)/2;
    }

    int left(int i){
        return 2*i + 1;
    }
    int right(int i ){
        return 2*i + 2;
    }
    void heapifyUp(int i){
        while(i > 0 &&  heap[parent(i)] < heap[i]){
            swap(heap[parent(i)], heap[i]);
            i = parent(i);
        }
    }
    void heapifyDown(int i){
        int largest = i ;
        int l = left(i);
        int r = right(i);
        if(l < heap.size() && heap[l] > heap[largest]) largest = l;
        if(r < heap.size() && heap[r] > heap[largest]) largest = r;

        if(largest != i)
        {
            swap(heap[i],heap[largest]);
            heapifyDown(largest);
        }
    }
    void insert(int val){
        heap.push_back(val);
        heapifyUp(heap.size() - 1);
    }   
    void pop(){
        if(heap.empty())return ;
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
    }
    int top(){
        if(heap.empty()) return -1;
        return heap[0];
    }
    bool isempty(){
        return heap.empty();
    }
};

int main(){
    Maxheap h;
    h.insert(10);
    h.insert(20);
    h.insert(5);
    h.insert(30);
    h.insert(15);   
    while(!h.isempty()){
        cout << h.top() << " ";
        h.pop();
    }
}
