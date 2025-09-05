#include<iostream>
#include<vector>
#include<stack>
#include<unordered_map>
using namespace std;

int main(){
unordered_map<int,int>m ; 
vector<int>arr1 = {6,1,8} ; 
vector<int> arr = {6,8,0,1,3}; 
vector<int> ans;
stack<int> s;
for(int i  = arr.size()-1 ; i>=0 ; i--){
    while(s.size() > 0 && s.top()<=arr[i] ){
        s.pop() ;
    }
    if(s.empty()){
       m[arr[i]] = -1;
    }
    else{
      m[arr[i]] = s.top() ;
    }
    s.push(arr[i]) ;
} 
for (int i = 0 ; i<arr1.size() ; i++){
    ans.push_back(m[arr1[i]]);
}
for (int val : ans){
    cout<< val << " " ;
}
cout<<endl ; 

return 0;
}