#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node(int data) {
        val = data;
        left = right = nullptr;
    }
};

Node* prevNode = nullptr;
int minDiffValue = INT_MAX;

void minDiff(Node* root) {
    if (root == nullptr)
        return;

    // Traverse left subtree
    minDiff(root->left);

    // Process current node
    if (prevNode != nullptr) {
        minDiffValue = min(minDiffValue, root->val - prevNode->val);
    }
    prevNode = root;

    // Traverse right subtree
    minDiff(root->right);
}

// Function to build tree from preorder with -1 as null
int idx = -1;
Node* BuildTree(vector<int>& vec1) {
    idx++;
    if (vec1[idx] == -1)
        return nullptr;
    Node* root = new Node(vec1[idx]);
    root->left = BuildTree(vec1);
    root->right = BuildTree(vec1);
    return root;
}

int main() {
    vector<int> vec1 = {4, 2, 1, -1, -1, 3, -1, -1, 6, 5, -1, -1, 7, -1, -1};
    Node* root = BuildTree(vec1);

    prevNode = nullptr;
    minDiffValue = INT_MAX;
    minDiff(root);

    cout << "Minimum difference between any two nodes is: " << minDiffValue << endl;
    return 0;
}
