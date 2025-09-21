// INORDER PREDECESSOR AND SUCCESSOR -->
#include <iostream>
#include <vector>
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

// Insert function
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

// Inorder Traversal (sorted order)
void inorder(Node* root) {
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
Node* rightMostinLeftSubtree(Node* root){
    
    while(root->right!=nullptr){
        
       root = root->right ; 
    }
    return root ; 
}
Node* leftMostValueInRightSubtree(Node* root){
      
    while(root->left!=nullptr){
      
       root = root->left ; 
    }
    return root;  ; 
}
vector<int> getPredSucc(Node* root , int key){
   Node* curr = root;
   Node* pred = NULL ;
   Node* succ = NULL ;

   while(curr != NULL){
    if(key < curr->data){
        succ = curr ;
        curr = curr->left ;
    }
    else if (key > curr->data) {
    pred = curr ;
    curr = curr->right ;
   }
   else{
    if(curr->left!=NULL){
       pred =  rightMostinLeftSubtree(curr->left);
    }
    if(curr->right!=NULL){
       succ = leftMostValueInRightSubtree(curr->right);
    }
    break ;
   }
  
}
 return {pred->data , succ->data} ; 
}

int main() {
    Node* root = nullptr;

    // Insert nodes into BST
    int values[] = {50, 30, 20, 40, 70, 60, 80};
    for (int val : values) {
        root = insert(root, val);
    }

    // Inorder traversal
    cout << "Inorder Traversal (sorted): ";
    inorder(root);
     cout<<endl;
     cout<<endl;
     int key = 50 ; 
     vector<int> ans  =getPredSucc( root , key) ;
     cout<<"Predecessor : "<<ans[0]<<endl;
     cout<<"successor : "<<ans[1]<<endl;
    return 0;
}
