// To display all the subarray of an aaray . 

#include<iostream>
#include<iomanip>
#include<vector>
#include<climits>
#include<climits>
#include<algorithm>
using namespace std;

int main(){
int n  = 5  ; 
int arr [5] = {1,-2,3,-4,5} ; 

// To display all the subarray of an aaray . 

for (int  st = 0 ; st < n ; st++){ // here we get the starting point of the array . 
    for (int end = st ; end < n ; end++){ // THis gives us the ending point of the array .
      for (int i  = st ;  i<= end ; i++){ // This helps us to print all the elements from start to end  . 
        cout<< arr[i]<<" " ;
      }
      cout<<" ; "<<"  " ; 
    }
    cout<<endl ; 
}   


//Brute force approach for calculating maximum sum by subarray .
 
  int maxsum = INT_MIN ; 
for (int  st = 0 ; st < n ; st++){ // here we get the starting point of the array . 
    int curr_sum = 0  ; 
    for (int end = st ; end < n ; end++){ // THis gives us the ending point of the array .
     curr_sum += arr[end] ;
     maxsum = max(curr_sum , maxsum) ; 


  
}}
     cout<<endl ;  
     cout<<endl ;  
        


// Using kadan's algorithm to calculate maximum sum of an array in more optimised way . 

int cursum = 0 ; maxsum= INT_MIN ; 
for (int val : arr){
    cursum  += val ; // Val here is the value of element . 
    maxsum = max(cursum , maxsum);
    if(cursum <= 0 ){
        cursum = 0 ;
    } 


}
    cout<<maxsum ; 
        
       
        
     
     
          
return 0;
}