// Kth level of a binary Tree -->
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
void KthLevel(Node* root , int k ){
    if(root == NULL){
        return ;
    }
    if(k==1){
        cout<<root->data<<" ";
        return ; 
    }
    KthLevel(root->left,k-1);
    KthLevel(root->right,k-1);
}





int main(){
vector<int>preorder = {1,2,-1,-1,3,4,-1,-1,5,-1,-1} ;
Node* root = buildTree(preorder) ;
KthLevel(root , 3);


return 0;
}