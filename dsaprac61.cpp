#include<iostream>
#include<vector>
#include<list>
using namespace std;
class stack_Vector {
   vector<int> v ;

   public :
    void push(int val) {
      v.push_back(val) ;
    }
    void pop(){
     v.pop_back() ;
    }
    int top(){
        return v[v.size()-1] ; 
    }
    bool empty(){
        return v.size() == 0 ;
    }
};
class stack_Linked_List {
   list<int> l ;

   public :
    void push(int val) {
      l.push_front(val) ;
    }
    void pop(){
      l.pop_front();
    }
    int top(){
      return l.front() ;
    }
    bool empty(){
        return l.size() == 0 ;
    }
};


int main(){
   stack_Vector s ;
   s.push(20);
   s.push(30);
   s.push(60);
   s.push(80);

   while(!s.empty()){
    cout<<s.top()<<" ";
    s.pop();
   }
   cout<<endl ;
   stack_Linked_List li ;
   li.push(20);
   li.push(30);
   li.push(60);
   li.push(80);

   while(!li.empty()){
    cout<<li.top()<<" ";
    li.pop();
   }
   cout<<endl ;
 

return 0;
}