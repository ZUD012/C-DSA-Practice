
#include<iostream>
#include<vector>

using namespace std;
class Node{
    public :
 int data ;
 Node*left ;
 Node*right ;

 Node(int val){
   data  = val ;
   left = right = NULL ;

 }
};

static int idx = -1;

 Node* buildTree(vector<int> preorder){
 idx++ ;
 if(preorder[idx]== -1){
    return NULL ;
 }
 Node*root = new Node(preorder[idx]);
 root->left = buildTree(preorder); //LEFT  
 root->right = buildTree(preorder) ;
 return root ;
 
}
void preOrder(Node* root){
   if(root == NULL){
    return ;
   }
   cout<<root->data << " " ;
   preOrder(root->left);
   preOrder(root->right);

}
Node* lowestCommonNcestor(Node* root , Node* p , Node* q ){
    if(root == NULL){
        return NULL ;
    }
    if(root->data==p->data || root->data == q->data){
        return root ; 
    }
    Node* leftLCA = lowestCommonNcestor(root->left , p , q);
    Node* rightLCA = lowestCommonNcestor(root->right , p , q);
    if(leftLCA && rightLCA){
        return root ;
    }
    else if (leftLCA !=NULL){
        return leftLCA;
    }
    else{
        return rightLCA;
    }
}






int main() {
    // Expanded preorder traversal: 1 with left and right subtrees deeper
    vector<int> preorder = {
        1, 
        2, 4, -1, -1, 5, -1, -1, 
        3, 6, -1, -1, 7, 8, -1, -1, -1
    };
    Node* root = buildTree(preorder);

    // Example: Find LCA of nodes 5 and 8
    Node* node5 = root->left->right;            // Node with value 5
    Node* node8 = root->right->right->left;     // Node with value 8

    Node* lca = lowestCommonNcestor(root, node5, node8);
    if (lca != NULL) {
        cout << "Lowest Common Ancestor of " << node5->data << " and " << node8->data << " is: " << lca->data << endl;
    } else {
        cout << "Lowest Common Ancestor not found." << endl;
    }

    return 0;
}
