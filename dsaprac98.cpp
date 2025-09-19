#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* buildBST (vector<int> &preorder , int &i , int bound){
        if(i>=preorder.size() || preorder[i] > bound){
            return NULL ;
        }
        TreeNode* root = new TreeNode (preorder[i++]) ;
        root->left = buildBST(preorder , i , root->val ) ; 
        root->right = buildBST(preorder , i , bound) ;
        return root ;  

    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i = 0 ;
    return buildBST(preorder , i , INT_MAX) ; 

    }
};


void printInorder(TreeNode* root) {
    if (!root) return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

int main() {
    Solution sol;
    vector<int> preorder = {8, 5, 1, 7, 10, 12}; // Example input

    TreeNode* root = sol.bstFromPreorder(preorder);

    cout << "Inorder Traversal of Constructed BST: ";
    printInorder(root); // should print sorted values if BST is correct
    cout << endl;

    return 0;
}
