// Working on queue and deque(DOUBLE ENDED QUEUE) using stl -->
#include<iostream>
#include<queue>
#include<deque>
using namespace std;

int main(){
queue<int>q ;
q.push(1);
q.push(2);
q.push(3);
while(!q.empty()){
    cout<<q.front()<<" ";
    q.pop();
}
cout<<endl ;

deque<int>d ;
d.push_back(1);
d.push_back(2);
d.push_back(3);

d.push_front(4);
cout<<d.front()<<" "<<d.back() <<endl ;
d.pop_back();
cout<<d.front()<<" "<<d.back() <<endl ;
return 0;
}