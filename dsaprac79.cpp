// BINARY TREES -->
#include<iostream>
#include<vector>
#include<queue>
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
// preorder -->
void preOrder(Node* root){
   if(root == NULL){
    return ;
   }
   cout<<root->data << " " ;
   preOrder(root->left);
   preOrder(root->right);

}
// preorder -->
void inOrder(Node* root){
   if(root == NULL){
    return ;
   }
   inOrder(root->left);
   cout<<root->data << " " ;
   inOrder(root->right);
}
// postorder -->
void postOrder(Node* root){
   if(root == NULL){
    return ;
   }
   postOrder(root->left);
   postOrder(root->right);
   cout<<root->data << " " ;
}
void levelorder(Node* root ){
   queue<Node*>q ; 
   q.push(root);
   while(q.size()>0){
      Node* curr = q.front();
      q.pop();
      cout<< curr->data<<" ";
      if(curr->left != NULL){
         q.push(curr->left);
      }
      if(curr->right != NULL){
         q.push(curr->right);
      }
   }
   cout<<endl ;
}
void levelorderuniqueprint(Node* root) {
    if (root == nullptr) return;  // ✅ handle empty tree

    queue<Node*> q;
    q.push(root);
    q.push(nullptr);  // marker for end of level

    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();

        if (curr == nullptr) {
            cout << endl;  // end of level
            if (!q.empty()) {
                q.push(nullptr);  // marker for next level
            }
        } else {
            cout << curr->data << " ";  // print node value
            if (curr->left != nullptr)
                q.push(curr->left);
            if (curr->right != nullptr)
                q.push(curr->right);
        }
    }
}


int main(){
vector<int>preorder = {1,2,-1,-1,3,4,-1,-1,5,-1,-1} ;
Node* root = buildTree(preorder) ;
cout<<root->data<<endl ;
cout<<root->left->data<<endl ;
cout<<root->right->data<<endl ;
preOrder(root) ;
cout<<endl ;
inOrder(root) ;
cout<<endl ;
postOrder(root) ;
cout<<endl ;
levelorder(root);
levelorderuniqueprint(root) ; 

return 0;
}