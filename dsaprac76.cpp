// First Unique Character in string .
#include<iostream>
#include<unordered_map>
#include<queue>
using namespace std;

class Solution{
 public:
 int firstIniqueChar(string s ){
    unordered_map<char , int > m ;
    queue<int> q ;
    for(int i = 0 ; i<s.size() ; i++){
        if(m.find(s[i]) == m.end()){
            q.push(i);
        }
        m[s[i]]++ ; //increases frequency
    }

    while(q.size()>0 && m[s[q.front()]] > 1){
       q.pop() ;
    }
    return q.empty() ? -1 : q.front() ; 
 }
};

int main(){
Solution solution ;
string s  = "LEVEL" ;
int idx = solution.firstIniqueChar(s) ;
cout<<"The index at which the Unique character exist is : "<<idx ; 




return 0;
}