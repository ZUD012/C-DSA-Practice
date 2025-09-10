// Counting No. of Nodes in a tree and Sum of three  --> 
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

int count(Node* root){
    if(root == NULL){
        return 0 ;
    }
    int leftHt = count(root->left);
    int rightHt=count(root->right);
    return leftHt+rightHt+1 ;
}
int sum(Node*root){
    if(root == NULL){
        return 0 ;
    }
    int leftsum = sum(root->left) ; 
    int rightsum = sum(root->right);
    return leftsum + rightsum + root->data ;
 }



int main(){
vector<int>preorder = {1,2,-1,-1,3,4,-1,-1,5,-1,-1} ;
Node* root = buildTree(preorder) ; 
cout<<"Total Number of nodes in the tree are : "<<count(root) ; 
cout<<endl ;
cout<<"Total sum of  the tree are : "<<sum(root) ; 
return 0;
}