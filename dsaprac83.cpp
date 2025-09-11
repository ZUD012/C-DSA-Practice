// TOp View of BINARY TREES -->
#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<utility>
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
void topView(Node* root){
    queue<pair<Node*,int>>q ; // pair along with horizontal  distance -->
    map<int , int > m ; // <HD ,Node val> -->
    q.push({root,0}) ;
    while(q.size()>0){
      Node* curr = q.front().first;
      int currHD = q.front().second;
      q.pop();
      if(m.find(currHD)==m.end()){
        m[currHD] = curr->data ; 
      }
      if(curr->left != NULL){
        q.push({curr->left , currHD - 1});
      }
      if(curr->right != NULL){
        q.push({curr->right , currHD + 1});
      }
    }
    for(auto it : m ){
        cout<<it.second<<" " ; 
    }
    cout<<endl ; 
}




int main(){
vector<int>preorder = {1,2,-1,-1,3,4,-1,-1,5,-1,-1} ;
Node* root = buildTree(preorder) ;
topView(root) ; 

return 0;
}