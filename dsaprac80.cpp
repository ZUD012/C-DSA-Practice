// Height of the tree -->
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std ;
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

int height(Node* root){
if(root==NULL){
    return 0;
}
int leftht = height (root->left) ;
int rightht= height (root->right) ;
return max(rightht,leftht)+1 ;
}

int main(){
vector<int>preorder = {1,2,-1,-1,3,4,-1,-1,5,-1,-1} ;
Node* root = buildTree(preorder) ; 
cout<<"height : "<<height(root)<<endl ;
return 0;
}