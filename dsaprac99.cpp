#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    // Helper function to perform inorder traversal
    void inorder(TreeNode* root, vector<int>& result) {
        if (!root) return;
        inorder(root->left, result);
        result.push_back(root->val);
        inorder(root->right, result);
    }

    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> v1, v2;
        inorder(root1, v1);
        inorder(root2, v2);

        // Merge two sorted arrays
        vector<int> merged;
        int i = 0, j = 0;
        while (i < v1.size() && j < v2.size()) {
            if (v1[i] < v2[j]) merged.push_back(v1[i++]);
            else merged.push_back(v2[j++]);
        }
        while (i < v1.size()) merged.push_back(v1[i++]);
        while (j < v2.size()) merged.push_back(v2[j++]);

        return merged;
    }
};

// Utility to insert nodes into BST
TreeNode* insertBST(TreeNode* root, int val) {
    if (!root) return new TreeNode(val);
    if (val < root->val) root->left = insertBST(root->left, val);
    else root->right = insertBST(root->right, val);
    return root;
}

int main() {
    // Example BST1: [2,1,4]
    TreeNode* root1 = nullptr;
    root1 = insertBST(root1, 2);
    root1 = insertBST(root1, 1);
    root1 = insertBST(root1, 4);

    // Example BST2: [1,0,3]
    TreeNode* root2 = nullptr;
    root2 = insertBST(root2, 1);
    root2 = insertBST(root2, 0);
    root2 = insertBST(root2, 3);

    Solution sol;
    vector<int> result = sol.getAllElements(root1, root2);

    cout << "Merged Sorted Elements: ";
    for (int x : result) cout << x << " ";
    cout << endl;

    return 0;
}
