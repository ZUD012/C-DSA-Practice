
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

Node* A_t_BST(vector<int> & nums , int st , int end ){
    if(st>end){
        return NULL ;
    }
    int mid  = st + (end-st) /2 ; 
    Node* root = new Node(nums[mid]) ; 
    root->left = A_t_BST(nums , st , mid-1);
    root->right = A_t_BST(nums , mid+1 , end);

    return root ; 
}




   int main() {
    vector<int> sortedArr = {-10, -3, 0, 5, 9};
    Node* root = A_t_BST(sortedArr, 0, sortedArr.size() - 1);

    cout << "Balanced BST created." << endl;

    return 0;
}




  

 