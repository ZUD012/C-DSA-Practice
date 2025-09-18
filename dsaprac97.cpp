#include <iostream>
using namespace std;

// Definition of a Binary Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// Function to insert nodes (simple BST insertion)
Node* insert(Node* root, int val) {
    if (root == nullptr) {
        return new Node(val);
    }
    if (val < root->data) {
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }
    return root;
}

// Function to find a node with given value
Node* findNode(Node* root, int val) {
    if (!root) return nullptr;
    if (root->data == val) return root;
    if (val < root->data) return findNode(root->left, val);
    return findNode(root->right, val);
}

// Function to find LCA in BST
Node* LCA(Node* root , Node* p , Node* q ){
    if(root == NULL ){
        return NULL ;
    }
    if(root->data > p->data && root->data > q-> data){
        return LCA(root->left , p , q) ; 
    }
    else if (root->data < p->data && root->data < q->data){
        return LCA(root->right , p , q) ;
    }
    else{
        return root ; 
    }
}

int main() {
    Node* root = nullptr;

    // Insert nodes
    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 15);
    root = insert(root, 3);
    root = insert(root, 7);
    root = insert(root, 12);
    root = insert(root, 18);

    // Find nodes
    Node* p = findNode(root, 3);
    Node* q = findNode(root, 7);

    // Find LCA
    Node* lca = LCA(root, p, q);
    if (lca) {
        cout << "LCA of " << p->data << " and " << q->data << " is: " << lca->data << endl;
    } else {
        cout << "LCA not found" << endl;
    }

    return 0;
}
