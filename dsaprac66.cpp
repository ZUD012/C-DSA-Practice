// Previous Smaller Element -->
#include<iostream>
#include<vector>
#include<stack>
using namespace std;



int main(){
vector<int> arr = {3,1,0,8,6};   

vector<int>ans;
stack<int> s;
for(int i = 0 ; i<arr.size();i++){
    while(s.size()>0 && s.top()>arr[i]){
        s.pop();
    }
    if(s.empty()){
        ans.push_back(-1);
    }
    else{
        ans.push_back(s.top());
    }
    s.push(arr[i]) ; 
}
for(int val : ans){
    cout<<val<<" " ;
}
cout<<endl ;
return 0;
}