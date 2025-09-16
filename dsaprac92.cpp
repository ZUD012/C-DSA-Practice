#include<iostream>
#include<vector>
using namespace std;

class Node {
    public:
    int data ;
    Node* left ;
    Node* right ;

    Node(int val){
        data = val ;
        left = right = NULL ;

    }
};
// BUILDING THE TREE -->
Node* insert(Node *root ,int  val){
    if(root == NULL){
        return new Node(val) ;
    }
    if(val < root->data) {
        root->left = insert(root->left , val) ;
    }
    else{
        root->right = insert(root->right ,val ) ; 
    }
    return root ;

}
Node* BUILDbst(vector<int> arr)
{
    Node* root  = NULL ; 
    for(int value : arr){
    root = insert(root,value) ; 
}
return root ; 
}
// SEARCHING IN A BST --> 

bool Search_IN_BST(Node* root,int key ){
  if(root == NULL){
    return false ; 
  }
  if(root->data == key){
    return true ;
  }
if(root->data > key ){
    return  Search_IN_BST(root->left , key) ;
}
else{
    return Search_IN_BST(root->right , key) ;
}
}

// DELETING A NODE IN  A TREE -->
Node* getINORDERsuccessor(Node* root){
  while(root!=NULL && root->left != NULL){
    root = root->left ;
  }
  return root ; 
}
Node* delete_the_Node(Node* root  , int key){
  if(root == NULL){
    return NULL;
  }
  if(key<root->data){
    root->left = delete_the_Node(root->left , key);
  }
  else if(key>root->data){
    root->right = delete_the_Node(root->right , key); 
  }
  else { 
   if(root->left ==NULL ){
    Node* temp = root->right ;
    delete root ;
    return temp  ;
   }
   else if (root->right ==NULL){
     Node* temp = root->left ;
     delete root ;
     return temp ;
   }
   else{
     Node* IS = getINORDERsuccessor(root->right) ;
     root->data = IS->data ;
     root->right = delete_the_Node(root->right , IS->data) ;
     
   }
  }
  return root ; 
}


// PRINTING OF THE TREE --> 
void inorder(Node* root){
    if(root==NULL){
        return  ;
    }
    inorder(root->left) ; 
   
    cout<<root->data<<" " ; 
     inorder(root->right);

}



int main(){
vector<int> arr = {3,2,1,5,6,4};
Node* root = BUILDbst(arr) ; 
inorder(root) ;
cout<<endl ; 
delete_the_Node(root , 6) ;
inorder(root) ;
cout<<endl ; 



return 0;
}