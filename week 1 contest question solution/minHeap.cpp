#include<bits/stdc++.h>
using namespace std;

class MinHeap{
    vector<int> heap;
    int parent(int i){
        return (i-1)/2;
    }
    int leftChild(int i)
    {
        return 2*i+1;
    }
    int rightChild(int i)
    {
        return 2*i+2;
    }

    void heapifyUp(int i)
    {
        while(i != 0 && heap[parent(i)] > heap[i])
        {
            swap(heap[i],heap[parent(i)]);
            i = parent(i);
        }
    }

    void heapifyDown(int i)
    {
        int small = i;
        int l = leftChild(i);
        int r = rightChild(i);

        if(l < heap.size() && heap[l] < heap[small])
        {
            small = l;
        }

        if(r < heap.size() && heap[r] < heap[small])
        {
            small = r;
        }

        if(small != i)
        {
            swap(heap[i],heap[small]);
            heapifyDown(small);
        }

    }
    public :
    void insert(int key)
    {
        heap.push_back(key);
        heapifyUp(heap.size()-1);
    }

    void print()
    {
        for(int val : heap)
        {
            cout<<val<<" ";
        }
    }
};

int main(){
    MinHeap h;
    h.insert(2);
    h.insert(1);
    h.insert(5);
    h.insert(4);
    h.insert(3);

    h.print();
    return 0;
}

