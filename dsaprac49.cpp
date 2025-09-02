// Linlked list --> 
#include<iostream>
#include<iomanip>
using namespace std;

class Node{
    public :
   int data ; 
   Node* next ; 
   Node(int val){
    data = val ; 
    next = NULL ; 
   }
};

class list {
    Node * head ; 
    Node * tail ;
    
public : 
 list(){
    head = tail = NULL ;
 }
void push_front(int val){
Node* newNode = new Node(val) ; // dynamic object 
if(head == NULL){
    head = tail = newNode ;
}
else{
    newNode->next = head ; 
    head = newNode ; 
}
} 
void push_back(int val){
 Node* newNode = new Node(val) ;

 if(head == NULL){
    head = tail = newNode;
 }
 else{
    tail->next = newNode ;
    tail = newNode ; 
 }
}
void pop_front(){
    if(head == NULL){
        cout<<"LL is empty ";
        return ; 
    }
    Node *temp = head ;
    head = head -> next;
    temp->next = NULL ; 

    delete temp ; 
}
void pop_back(){
    if(head == NULL){
        cout<<"LL is empty";
        return ;
    }
    Node* temp = head ; 
    while(temp->next != tail){
        temp = temp->next ;
    }
    temp->next = NULL ; 
    delete tail ;
    tail = temp ; 
}
void insert(int val , int pos ){
     if(pos<0){
        cout<<"invlaid Position";
        return ;
     }

     if(pos == 0){
        push_front(val);
     }
     Node* temp = head;
     for(int i=0 ; i<pos-1 ; i++){
        temp = temp->next;
     }
     Node* newNode = new Node(val);
     newNode->next = temp->next ;
     temp->next = newNode ;
}
void printll(){
    Node * temp = head ; 
    while(temp != NULL ){
      cout<< temp->data<<" " ;
      temp = temp->next ; 
    }
    cout<<endl ; 
}
};
int main(){
list l1 ;
l1.push_front(1);
l1.push_front(2);
l1.push_front(3);
l1.push_back(4);
l1.pop_front();
l1.pop_back();
l1.insert(4,1);
l1.printll() ;

return 0;
}