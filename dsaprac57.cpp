// Circular Linked List -->

#include<iostream>
#include<iomanip>
using namespace std;
class Node {
    public :
    int data ;
    Node* next ;
    Node(int val ){
        data = val ;
        next = NULL ;
    }
};
class circular_List{
    Node* head ;
    Node* tail ;
    public :
    circular_List(){
        head = tail = NULL ;
    }
 void Insert_head(int val){
    Node* newNode = new Node(val) ;
    if (head ==NULL){
        head = tail = newNode ;
        tail->next = head ; 
    }
    else {
    newNode->next =head ; 
    head = newNode ;
    tail->next = head;  
    }
 }

 void Insert_tail(int val){
    Node* newNode = new Node(val) ;
    if (head ==NULL){
        head = tail = newNode ;
        tail->next = head ; 
    }
    else {
    newNode->next =head ; 
    tail->next = newNode ;
    tail = newNode ; 
    }
 }

 void delete_at_head(){    
    Node* temp = head ; 
    if (head ==NULL){
        return ;
    }
    else if(head == tail ){
        delete head; 
        head = tail = NULL ; 
    }
    else{
        head = head->next;
        tail->next = head; 
        temp->next = NULL ;
        delete temp ;
    }
   
 }
 void delete_at_tail(){    
    Node* temp = tail ; 
    Node* prev = head ; 
    if (head ==NULL){
        return ;
    }
    else if(head == tail ){
        delete head; 
        head = tail = NULL ; 
    }
    else{
         while(prev->next!=tail){
            prev = prev->next ;
         }
             tail = prev ;
             tail->next = head ;
             temp->next = NULL ;
             delete temp ;  
             
         
    }
   
 }

 void print (){
    if(head == NULL){return;}
    cout<<head->data<<" -> ";
    Node* temp = head->next ; 
    while(temp !=head){
        cout<<temp->data<<" -> ";
        temp = temp->next ;
    }
    cout<<head->data<<endl ; 
 } 
};

int main(){
circular_List cl1 ;
cl1.Insert_head(1);
cl1.Insert_head(2);
cl1.Insert_tail(3);
cl1.Insert_tail(4);
cl1.Insert_tail(5);
cl1.delete_at_head();
cl1.delete_at_tail();
cl1.print() ;
return 0;
}