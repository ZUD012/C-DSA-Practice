// FLATTEN BINARY TREE TO LINKED LIST -->
#include<iostream>
#include<vector>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

static int idx = -1;

// Build tree from preorder traversal where -1 represents NULL node
Node* buildTree(vector<int>& preorder) {
    idx++;
    if (preorder[idx] == -1) {
        return NULL;
    }
    Node* root = new Node(preorder[idx]);
    root->left = buildTree(preorder);
    root->right = buildTree(preorder);
    return root;
}

Node* next_Right = NULL;

// Flatten the binary tree to a linked list in-place
void flatten(Node* root) {
    if (root == NULL) {
        return;
    }
    flatten(root->right);
    flatten(root->left);
    root->left = NULL;
    root->right = next_Right;
    next_Right = root;
}

// Function to print the flattened tree
void printFlattened(Node* root) {
    Node* curr = root;
    while (curr != NULL) {
        cout << curr->data << " ";
        curr = curr->right;
    }
    cout << endl;
}

int main() {
    vector<int> preorder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    Node* root = buildTree(preorder);

    flatten(root);

    cout << "Flattened tree (right-skewed linked list): ";
    printFlattened(root);

    return 0;
}
