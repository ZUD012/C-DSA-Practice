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

// Find all root-to-leaf paths and store as strings
void allPaths(Node* root, string path, vector<string>& ans) {
    if (root->left == NULL && root->right == NULL) {
        ans.push_back(path);
        return;
    }
    if (root->left) {
        allPaths(root->left, path + "->" + to_string(root->left->data), ans);
    }
    if (root->right) {
        allPaths(root->right, path + "->" + to_string(root->right->data), ans);
    }
}

vector<string> binaryPath(Node* root) {
    vector<string> ans;
    string path = to_string(root->data);
    allPaths(root, path, ans);
    return ans;
}

// Convert the tree into a Sum Tree where each node's data becomes the sum of left and right subtree values including itself
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
    cout << "\n\n";

    cout << "All root-to-leaf paths before Sum Tree:\n";
    vector<string> paths = binaryPath(root);
    for (const string& path : paths) {
        cout << path << endl;
    }
    cout << "\n";

    // Convert the tree into a Sum Tree
    SumTree(root);

    cout << "Preorder after Sum Tree transformation:\n";
    preOrder(root);
    cout << "\n\n";

    cout << "All root-to-leaf paths after Sum Tree:\n";
    paths = binaryPath(root);
    for (const string& path : paths) {
        cout << path << endl;
    }
    cout << "\n";

    return 0;
}
