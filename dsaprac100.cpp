// RECOVER A BST -->


/*
💡 Problem: Recover Binary Search Tree

Two elements of a Binary Search Tree (BST) are swapped by mistake.
You need to recover the tree without changing its structure.

-------------------------------------------------------------------
Example 1:

Input: root = [1,3,null,null,2]
Output: [3,1,null,null,2]
Explanation: 3 and 1 are swapped. Restore them to get a valid BST.

-------------------------------------------------------------------
Example 2:

Input: root = [3,1,4,null,null,2]
Output: [2,1,4,null,null,3]
Explanation: 2 and 3 are swapped. Restore them to get a valid BST.

-------------------------------------------------------------------
Constraints:
- The number of nodes in the tree is in the range [2, 1000].
- -2^31 <= Node.val <= 2^31 - 1
-------------------------------------------------------------------
Follow up:
- A solution using O(n) space is easy (inorder traversal + sorting).
- Can you do it using only O(1) extra space?
-------------------------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *l, TreeNode *r) : val(x), left(l), right(r) {}
};

class Solution {
public:
    void recoverTree(TreeNode* root) {
        // usinng preorder traversal ;
        TreeNode* prev  = nullptr ;
        TreeNode* first = nullptr ;
        TreeNode* sec = nullptr ; 
        if(root == NULL){
            return ;
        }
        recoverTree(root->left);
        if(prev!=nullptr && root->val < prev->val){
            if(first==nullptr){
                first  = first = prev; 
            }
            sec = root ; 
        }
         prev  = root ; 
         recoverTree(root->right);


    }
    void FINALDONE(TreeNode* root){
        TreeNode* prev = nullptr ;
        TreeNode* first = nullptr ;
        TreeNode* sec = nullptr ;
        recoverTree(root);
        int temp = first->val ;
        first->val = sec->val ;
        sec->val = temp ;
        
    }
};

// ----------- Example Driver Code (For Testing) -------------
TreeNode* insertLevelOrder(vector<int> arr, int i) {
    if (i >= arr.size() || arr[i] == INT_MIN) return nullptr;
    TreeNode* root = new TreeNode(arr[i]);
    root->left = insertLevelOrder(arr, 2*i+1);
    root->right = insertLevelOrder(arr, 2*i+2);
    return root;
}

void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {
    // Example: [3,1,4,null,null,2]
    vector<int> arr = {3,1,4,INT_MIN,INT_MIN,2};
    TreeNode* root = insertLevelOrder(arr, 0);

    cout << "Before recovery (inorder): ";
    inorder(root);
    cout << endl;

    Solution().recoverTree(root);

    cout << "After recovery (inorder): ";
    inorder(root);
    cout << endl;
    return 0;
}
