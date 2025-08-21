// Subarray sum equal to K
#include<iostream>
#include<iomanip>
#include<vector>
#include<unordered_map>
using namespace std;

int subarraySum(vector<int> arr  , int k){
  int n = arr.size();
  int count = 0 ;
  vector<int> ps(n , 0) ;
  
  ps[0] = arr[0];
  for(int i = 1 ; i < n ; i++){
    ps[i] = ps[i-1]+ arr[i];
  }
   unordered_map<int,int> m ; 
   m[0] = 1 ;
    for(int j = 0 ; j<n ; j++ ){
        int val = ps[j] ;
        if(m.find(ps[j] - k) != m.end()){
            count+= m[val - k] ;
        }
        if (m.find(ps[j]) == m.end()){
            m[ps[j] ] = 0  ;
        }
        m[ps[j]]++;
    }
    return count ;
}
int main(){
vector<int> a ={1,2,3} ;
int target = 3 ;
cout<<subarraySum( a  ,target) ;
return 0;
}