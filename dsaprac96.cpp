// Kth Smallest in Binary Tree Search -->
#include <iostream>
using namespace std;

// Definition of a Binary Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// Function to insert nodes (simple BST insertion for example)
Node* insert(Node* root, int val) {
    if (root == nullptr) {
        return new Node(val);
    }

    if (val < root->data) {
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }
    return root;
}

int counter = 0; // global counter

int Kth_BST(Node* root, int k) {
    if (root == nullptr) {
        return -1;
    }

    // Search in left subtree
    int left_ans = Kth_BST(root->left, k);
    if (left_ans != -1) return left_ans;

    // Visit current node
    counter++;
    if (counter == k) {
        return root->data;
    }

    // Search in right subtree
    int right_ans = Kth_BST(root->right, k);
    if (right_ans != -1) return right_ans;

    return -1; // if not found
}

int main() {
    Node* root = nullptr;

    // Insert nodes into the binary tree (BST style)
    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 15);
    root = insert(root, 3);
    root = insert(root, 7);
    root = insert(root, 12);
    root = insert(root, 18);

    int k = 3; // Example: 3rd smallest
    int result = Kth_BST(root, k);

    if (result != -1) {
        cout << k << "-th smallest element is: " << result << endl;
    } else {
        cout << "Tree has fewer than " << k << " elements." << endl;
    }

    return 0;
}
