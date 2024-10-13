
#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>

using namespace std;

// A Huffman tree node
struct Node {
    char ch;
    int freq;
    Node *left, *right;

    Node(char c, int f) {
        ch = c;
        freq = f;
        left = right = nullptr;
    }
};

// Comparator to order the priority queue (min-heap) by frequency
struct compare {
    bool operator()(Node* l, Node* r) {
        return l->freq > r->freq;
    }
};

// Function to print the Huffman Codes for each character
void printCodes(struct Node* root, string str) {
    if (!root)
        return;

    // If it's a leaf node, print character and its code
    if (root->ch != '$')
        cout << root->ch << ": " << str << "\n";

    printCodes(root->left, str + "0");
    printCodes(root->right, str + "1");
}

// Function to build Huffman Tree and generate codes
void huffmanEncoding(vector<char>& characters, vector<int>& frequencies) {
    int n = characters.size();

    // Create a priority queue (min-heap) to store nodes of the Huffman tree
    priority_queue<Node*, vector<Node*>, compare> minHeap;

    // Create a leaf node for each character and add it to the min-heap
    for (int i = 0; i < n; ++i) {
        minHeap.push(new Node(characters[i], frequencies[i]));
    }

    // Iterate while the heap contains more than one node
    while (minHeap.size() != 1) {
        // Extract the two nodes with the lowest frequency
        Node *left = minHeap.top(); minHeap.pop();
        Node *right = minHeap.top(); minHeap.pop();

        // Create a new internal node with a frequency equal to the sum of the two nodes
        Node *top = new Node('$', left->freq + right->freq);
        top->left = left;
        top->right = right;

        // Add the new node to the min-heap
        minHeap.push(top);
    }

    // The remaining node is the root of the Huffman Tree
    printCodes(minHeap.top(), "");
}

int main() {
    vector<char> characters = { 'a', 'b', 'c', 'd', 'e', 'f' };
    vector<int> frequencies = { 5, 9, 12, 13, 16, 45 };

    cout << "Huffman Codes:\n";
    huffmanEncoding(characters, frequencies);

    return 0;
}
