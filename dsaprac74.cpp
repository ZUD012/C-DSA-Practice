// CIrcular Queue --> 
#include<iostream>
#include<iomanip>
using namespace std;

class circularQueue{
  int* arr ;
  int currSize , cap ; 
  int f , r ;
  public :
  circularQueue(int size){
    cap = size;
    arr = new int[cap];
    currSize = 0 ;
    f= 0;
    r = -1 ;
  }
  void push(int data){
   if(currSize == cap){
    cout<<"CQ is full\n";
    return ;
   }
   else{
    r = (r+1)%cap ;
    arr[r] = data ;
    currSize++ ;   
}

  }
  void pop(){
    if(empty()){
    cout<<"CQ is empty\n";
    return ;
   }
   f=(f+1)% cap ;
   currSize -- ;
  }
  int front(){
     if(empty()){
    cout<<"CQ is empty\n";
    return -1;
   }
   cout<<arr[f] ;
  }
  bool empty(){
    return currSize == 0 ; 
  }
  void printarr(){
    for(int i = 0 ; i<3 ; i++){
     cout<<arr[i]<<" " ;
  }
  }
};
int main(){
circularQueue cq(3) ;

cq.push(1);
cq.push(2);
cq.push(3);
cq.pop();
cq.push(4);
cq.printarr(); 

return 0;
}