// Design a  min stack -->
#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;

class Minstack {
public:
  stack<long long int>s ;
  long long int minval ;
  void push(int val){
    if (s.empty()){
    minval = val ;
    s.push(val);
    }
    else if (val < minval){
        s.push((long long) 2*val - minval);
        minval = val ; 
    }
    else {
        s.push (val) ;
    }
  }
  void pop(){
    if(s.top() < minval){
        minval = 2*minval - s.top() ;
    }
    s.pop() ;
  }
  int top(){
    if(s.top() < minval){
        return minval ;
    }
    else{
        return s.top() ;
    }
  }
  int getMin(){
    return minval ;
  }
};

int main() {
    Minstack minStack;
    minStack.push(3);
    minStack.push(5);
    cout << "Top: " << minStack.top() << endl;        // 5
    cout << "Min: " << minStack.getMin() << endl;     // 3
    minStack.push(2);
    minStack.push(1);
    cout << "Min: " << minStack.getMin() << endl;     // 1
    minStack.pop();
    cout << "Min: " << minStack.getMin() << endl;     // 2
    minStack.pop();
    cout << "Top: " << minStack.top() << endl;        // 5
    cout << "Min: " << minStack.getMin() << endl;     // 3
    return 0;
}
