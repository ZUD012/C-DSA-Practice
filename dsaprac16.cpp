// Pianter partition problem -->

// To minimise the maximum time taken by any painter -> 

#include<iostream>
#include<iomanip>
#include<vector>

using namespace std;

bool isvalid(vector<int> &vec1 , int m  , int n , int maximum_time  ){
       int painter = 1 ;
       int time = 0 ;
       for (int i = 0 ; i<n ; i++){
        
        if (vec1[i] > maximum_time){
            return false ; 
        }
        if (time + vec1[i]<= maximum_time){
            time += vec1[i] ;  
        }
        else{
            painter++ ; 
            time = vec1[i] ; 
        }
       }
       return painter > m ? false : true ; 
}

int Painter_partition(vector<int> &vec1 , int m  , int n ){
  int start = 0 ;
  int mid ;
  int sizee = vec1.size() ; 
  int sum = 0 ;
for (int i = 0 ; i < sizee  ; i++) {
  sum += vec1[i] ; 
}
  int end = sum  ;
  int ans = 0  ; 
    while(start<= end ){
        mid = start + (end-start)/2 ; 
        if(isvalid(vec1 ,  m  ,  n , mid)){
            ans = mid ;
            end = mid - 1 ; 
        }
        else{
            start = mid + 1; 
        }
    }

 return ans ;
}

int main(){
vector <int> vec1 = {40 , 20 ,10 , 20} ; 
int m = 2 ; 
int n = 4 ; 
cout<<Painter_partition(vec1 ,  m  ,  n ) ; 


return 0;
}