#include<iostream>
#include<iomanip>
#include<vector>
using namespace std;

// Binary search using recursion -->
int binsearch(vector<int> &arr , int tar ,int st ,int end ){
   if(st<=end){
      int mid = st +(end-st)/2 ;

      if (arr[mid]==tar){
         return mid ; 
      }
      else if (arr[mid] <= tar){
        return binsearch(arr , tar , mid+1, end) ;
      }
      else{
          return binsearch(arr , tar , st , mid - 1) ;
      }
   }
   return -1 ;
}




// Check whether array is sorted using recursion -->

bool issorted(vector<int> arr , int n ){
   if(n == 0 || n == 1 ){
    return true ;
   }
   return arr[n-1] >=arr[n-2] && issorted(arr , n-1) ;
}


int main(){

vector<int> arr = {1,2,4,6,8,10};
cout<<issorted( arr ,  6 )<<endl;

cout<<binsearch( arr ,  8 , 0 , 5 ) ;

return 0;
}

