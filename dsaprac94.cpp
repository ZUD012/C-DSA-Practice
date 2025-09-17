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
        left = right = nullptr;
    }
};

// Function to build a balanced BST from sorted array
Node* sortedArrayToBST(vector<int>& arr, int start, int end) {
    if (start > end)
        return nullptr;

    int mid = start + (end - start) / 2;
    Node* root = new Node(arr[mid]);

    root->left = sortedArrayToBST(arr, start, mid - 1);
    root->right = sortedArrayToBST(arr, mid + 1, end);

    return root;
}

// Function to validate BST
bool ValidateBSt(Node* root, Node* min, Node* max) {
    if (root == nullptr)
        return true;

    if (min != nullptr && root->data <= min->data)
        return false;

    if (max != nullptr && root->data >= max->data)
        return false;

    return ValidateBSt(root->left, min, root) &&
           ValidateBSt(root->right, root, max);
}

// Inorder traversal to print the BST
void inorder(Node* root) {
    if (root == nullptr)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    vector<int> sortedArr = {-10, -3, 0, 5, 9};

    // Build balanced BST from sorted array
    Node* root = sortedArrayToBST(sortedArr, 0, sortedArr.size() - 1);

    // Print inorder traversal
    cout << "Inorder Traversal of BST:" << endl;
    inorder(root);
    cout << endl;

    // Validate if it's a BST
    if (ValidateBSt(root, nullptr, nullptr))
        cout << "The tree is a valid BST." << endl;
    else
        cout << "The tree is NOT a valid BST." << endl;

    return 0;
}
