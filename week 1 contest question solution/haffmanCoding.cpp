#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

// Tree node
struct Node {
    char ch;
    int freq;
    Node* left;
    Node* right;

    Node(char c, int f) : ch(c), freq(f), left(nullptr), right(nullptr) {}
};

// Custom comparator for min-heap
struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq;
    }
};

// Recursive function to generate Huffman codes
void generateCodes(Node* root, string code, unordered_map<char, string>& huffmanCodes) {
    if (!root) return;

    if (!root->left && !root->right) {
        huffmanCodes[root->ch] = code;
    }

    generateCodes(root->left, code + "0", huffmanCodes);
    generateCodes(root->right, code + "1", huffmanCodes);
}

// Main Huffman function
void huffmanCoding(const unordered_map<char, int>& frequencies) {
    // Step 1: Create min-heap (priority queue)
    priority_queue<Node*, vector<Node*>, Compare> minHeap;

    for (auto& pair : frequencies) {
        minHeap.push(new Node(pair.first, pair.second));
    }

    // Step 2: Build Huffman tree
    while (minHeap.size() > 1) {
        Node* left = minHeap.top(); minHeap.pop();
        Node* right = minHeap.top(); minHeap.pop();

        Node* merged = new Node('\0', left->freq + right->freq);
        merged->left = left;
        merged->right = right;

        minHeap.push(merged);
    }

    // Step 3: Final node is root of Huffman Tree
    Node* root = minHeap.top();

    // Step 4: Traverse tree and assign codes
    unordered_map<char, string> huffmanCodes;
    generateCodes(root, "", huffmanCodes);

    // Print Huffman codes
    cout << "Huffman Codes:\n";
    for (auto& pair : huffmanCodes) {
        cout << pair.first << " : " << pair.second << "\n";
    }
}

int main() {
    unordered_map<char, int> frequencies = {
        {'a', 5},
        {'b', 9},
        {'c', 12},
        {'d', 13},
        {'e', 16},
        {'f', 45}
    };

    huffmanCoding(frequencies);
    return 0;
}
