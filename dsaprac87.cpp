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

// Preorder traversal to print the tree
void preOrder(Node* root) {
    if (root == NULL) {
        return;
    }
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

// Convert to Sum Tree by updating each node with sum of left and right subtrees including itself
int SumTree(Node* root) {
    if (root == NULL) {
        return 0;
    }
    int leftSum = SumTree(root->left);
    int rightSum = SumTree(root->right);
    root->data = root->data + leftSum + rightSum;
    return root->data;
}

int main() {
    vector<int> preorder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    Node* root = buildTree(preorder);

    cout << "Preorder before Sum Tree transformation:\n";
    preOrder(root);
    cout << "\n";

    SumTree(root);

    cout << "Preorder after Sum Tree transformation:\n";
    preOrder(root);
    cout << "\n";

    return 0;
}
