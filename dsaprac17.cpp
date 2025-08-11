// Aggrressive cow problem --> 

// Using binary search .

#include<iostream>
#include<iomanip>
#include<vector>
#include<algorithm>
using namespace std;

bool is_possible(vector<int> arr,int n,int c,int mid){
        int cow = 1 , laststallpos = arr[0] ; 
        for (int i = 0 ;  i < n ; i++){
            if (arr[i] - laststallpos >= mid){
                cow++ ; 
                laststallpos = arr[i] ; 
            }
            if (cow == c) {
                return true ;
            }
        }
        return false ; 
}


int getdistance(vector<int> &arr , int n , int c){
    sort(arr.begin() , arr.end()) ; 
  int start =1 , end = arr[n-1] -  arr[0] ; 
   int ans = 0 ;
  while(start<= end){
    int mid = start+(end-start)/2 ;

    if(is_possible(arr,n,c,mid)){ // right
        ans = mid ;
        start = mid + 1 ;
    }
    else{ //left
      
        end = mid -1 ;
    }
  } 
  return ans ; 
}



int main(){
vector<int> vec1 = {1,2,8,4,9} ; 
int n = 5 , c = 3 ; 
cout<<getdistance(vec1 ,  n ,  c) ;
return 0;
}