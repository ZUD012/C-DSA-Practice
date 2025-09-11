// Diameter of a binary tree -->
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
int ans  = 0 ;
int diameter_using_height(Node* root){
if(root==NULL){
    return 0;
}
int leftht = height (root->left) ;
int rightht= height (root->right) ;
ans = max(leftht+rightht , ans) ;
return max(rightht,leftht)+1 ;
}
int diameter_optimised(Node*root){
    diameter_using_height(root);
    return ans ; 
}

int diameter(Node* root){
    if(root== NULL){
     return 0 ;
    }
    int leftdiam = diameter(root->left) ;
    int rightdiam = diameter(root->right) ;
    int currDiam = height(root->left)+height(root->right) ; 
    return max(currDiam ,max (leftdiam , rightdiam)) ; 
}

int main(){
vector<int>preorder = {1,2,-1,-1,3,4,-1,-1,5,-1,-1} ;
Node* root = buildTree(preorder) ; 
int ans = diameter( root) ;
cout<<"The diameter of The tree is : "<<ans<<endl  ; 
int optimised = diameter_optimised(root) ;
cout<<"The diameter of the tree using optimised way is : "<<optimised ; 

return 0;
}