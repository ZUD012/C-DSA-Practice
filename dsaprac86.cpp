// Building Tree using preorder and Inorder -->
#include<iostream>
#include<vector>

using namespace std;

// Node structure
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

// Function to print preorder traversal
void preOrder(Node* root) {
    if (root == NULL) {
        return;
    }
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

// Search for value in inorder array between left and right indices
int search(vector<int>& inorder, int left, int right, int val) {
    for (int i = left; i <= right; i++) {
        if (inorder[i] == val) {
            return i;
        }
    }
    return -1;
}

// Helper function to build the tree recursively
Node* helper(vector<int>& preorder, vector<int>& inorder, int& preIdx, int left, int right) {
    if (left > right) {
        return NULL;
    }

    Node* root = new Node(preorder[preIdx]);

    // Find the index of the root in inorder
    int inIdx = search(inorder, left, right, preorder[preIdx]);
    preIdx++;

    // Build left and right subtrees
    root->left = helper(preorder, inorder, preIdx, left, inIdx - 1);
    root->right = helper(preorder, inorder, preIdx, inIdx + 1, right);

    return root;
}

// Wrapper function to initiate building the tree
Node* buildTree(vector<int>& preorder, vector<int>& inorder) {
    int preIdx = 0;
    return helper(preorder, inorder, preIdx, 0, inorder.size() - 1);
}

// Main function
int main() {
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};

    Node* root = buildTree(preorder, inorder);

    cout << "Preorder traversal of the constructed tree:" << endl;
    preOrder(root);
    cout << endl;

    return 0;
}
