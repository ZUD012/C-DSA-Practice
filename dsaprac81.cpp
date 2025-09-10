// Identical Tree or Subtree for Another Tree -->
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

// Function to build the tree from preorder traversal
Node* buildTree(vector<int>& preorder) {
    idx++;
    if (idx >= preorder.size() || preorder[idx] == -1) {
        return NULL;
    }
    Node* root = new Node(preorder[idx]);
    root->left = buildTree(preorder);
    root->right = buildTree(preorder);
    return root;
}

// Function to check if two trees are the same
bool isSameTree(Node* p, Node* q) {
    if(p == NULL || q == NULL) {
        return p == q;
    }
    bool isLeftSame = isSameTree(p->left, q->left);
    bool isRightSame = isSameTree(p->right, q->right);
    return isLeftSame && isRightSame && p->data == q->data;
}

// Helper function to check if two trees are identical
bool isIdentical(Node* p, Node* q) {
    if(p == NULL || q == NULL) {
        return p == q;
    }
    return p->data == q->data &&
           isIdentical(p->left, q->left) &&
           isIdentical(p->right, q->right);
}

// Function to check if 'subroot' is a subtree of 'root'
bool isSubtree(Node* root, Node* subroot) {
    if(root == NULL) {
        return false;
    }
    if(isIdentical(root, subroot)) {
        return true;
    }
    return isSubtree(root->left, subroot) || isSubtree(root->right, subroot);
}

int main() {
    vector<int> preorder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};

    idx = -1;
    Node* root1 = buildTree(preorder);

    idx = -1;
    Node* root2 = buildTree(preorder);

    if (isSameTree(root1, root2)) {
        cout << "The trees are the same." << endl;
    } else {
        cout << "The trees are different." << endl;
    }

    if (isSubtree(root1, root2)) {
        cout << "subroot is a subtree of root." << endl;
    } else {
        cout << "subroot is NOT a subtree of root." << endl;
    }

    return 0;
}
