#include<bits/stdc++.h>
using namespace std;

struct MinHeap {
    vector<int> heap;
    int parent(int i){
        return (i-1)/2;
    }

    int left(int i){
        return 2*i +1;
    }
    int right(int i){
        return 2*i +2;
    }

    void heapifyUP(int i){
        while(i > 0 && heap[parent(i)] > heap[i]){
            swap(heap[parent(i)],heap[i]);
            i = parent(i);
        }
    }

    void heapifyDown(int i){
        int smallest = i;
        int l = left(i);
        int r = right(i);
        if(l < heap.size() && heap[l] < heap[smallest]){
            smallest = l;
        }
        if(r < heap.size() && heap[r] < heap[smallest]){
            smallest = r;
        }


        if(smallest != i){
            swap(heap[i],heap[smallest]);
            heapifyDown(smallest);
        }
    }
    public:
    void insert(int val){
        heap.push_back(val);
        heapifyUP(heap.size() - 1);
    }
    void pop(){
        if(heap.empty()) return;
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
    }

    int top(){
        if(heap.empty())return -1;
        return heap[0];
    }
    bool isempty(){
        return heap.empty();
    }
};
int main(){
    MinHeap m;
    m.insert(10);
    m.insert(5);
    m.insert(20);
    m.insert(3);
    m.insert(15);
    while(!m.isempty()){
        cout << m.top() << " ";
        m.pop();
    }
}