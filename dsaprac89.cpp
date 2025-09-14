// Calculating Width Of a Tree -->
#include<iostream>
#include<vector>
#include<queue>

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

// Calculate the maximum width of the binary tree
int WidthOfBinaryTree(Node* root) {
    if (!root) return 0;

    queue<pair<Node*, int>> q;
    q.push({root, 0});
    int MaxWidth = 0;

    while (!q.empty()) {
        int curr_size = q.size();
        int STIdx = q.front().second;
        int endIdx = q.back().second;

        MaxWidth = max(MaxWidth, endIdx - STIdx + 1);

        for (int i = 0; i < curr_size; i++) {
            pair<Node*, int> curr = q.front();
            q.pop();
            Node* node = curr.first;
            int idx = curr.second - STIdx; // Normalize index to avoid overflow

            if (node->left) {
                q.push({node->left, 2 * idx + 1});
            }
            if (node->right) {
                q.push({node->right, 2 * idx + 2});
            }
        }
    }
    return MaxWidth;
}

int main() {
    vector<int> preorder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    Node* root = buildTree(preorder);

    cout << "Preorder traversal of the tree:\n";
    preOrder(root);
    cout << "\n\n";

    int width = WidthOfBinaryTree(root);
    cout << "Maximum width of the binary tree: " << width << endl;

    return 0;
}
