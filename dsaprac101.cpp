// Populating Next right Pointer in Each Node -->
#include <bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}
    Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {}
    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};



// Optional: helper function to print next pointers for testing
void printNextPointers(Node* root) {
    while (root) {
        Node* curr = root;
        while (curr) {
            cout << curr->val << "->";
            if (curr->next) cout << curr->next->val << " ";
            else cout << "NULL ";
            curr = curr->next;
        }
        cout << endl;
        root = root->left;
    }
}
Node* connect(Node*root){
    if(root == NULL || root->left == NULL){
        return root;
    }
    queue<Node*> q ;
    q.push(root) ;
    q.push(NULL);
    Node* prev = NULL ;
    while(q.size()>0){
        Node*curr = q.front() ;
        q.pop() ;
        if(curr == NULL){
           if(q.size()==0){
            break ;
           }
           else{
            q.push(NULL) ; 
           }
        }
        else{
            if(curr->left!=NULL){
                q.push(curr->left);
            }
            if(curr->right!=NULL){
                q.push(curr->right);
            }
            if(prev!=NULL){
                prev->next = curr;
            }

        }
        prev = curr ; 
    }
    return root ;
}

// Example usage
int main() {
    // Create a perfect binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    // Connect next pointers
    root = connect(root);

    // Print next pointers level by level
    printNextPointers(root);

    return 0;
}

