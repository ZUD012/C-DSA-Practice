#include <iostream>
#include <stack>
using namespace std;

// Definition of TreeNode
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BSTIterator {
public:
    stack<TreeNode*> s;

    // Helper function to store all left nodes
    void storeLeftNodes(TreeNode* root) {
        while (root != NULL) {
            s.push(root);
            root = root->left;  // go left, not next
        }
    }

    // Constructor
    BSTIterator(TreeNode* root) {
        storeLeftNodes(root);
    }

    // Return next smallest number
    int next() {
        TreeNode* ans = s.top();
        s.pop();
        storeLeftNodes(ans->right);  // handle right subtree
        return ans->val;
    }

    // Return whether we have a next smallest number
    bool hasNext() {
        return !s.empty();
    }
};

int main() {
    // Example BST:
    //       7
    //      / \
    //     3   15
    //         / \
    //        9  20

    TreeNode* root = new TreeNode(7);
    root->left = new TreeNode(3);
    root->right = new TreeNode(15);
    root->right->left = new TreeNode(9);
    root->right->right = new TreeNode(20);

    BSTIterator it(root);

    while (it.hasNext()) {
        cout << it.next() << " ";
    }
    // Output: 3 7 9 15 20  (in-order traversal)

    return 0;
}
