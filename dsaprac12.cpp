// Search in rotated sorted array -->
// ascending order -> distinct values ->

#include<iostream>
#include<iomanip>
#include<vector>

using namespace std;

int Binarysearch_2(vector<int>& vec1 , int sizee , int target){
    int start = 0 ;
    int end = sizee - 1 ; 
    while(start<=end){
    int mid = start + (end - start)/2  ;
    if(vec1[mid]==target){
        return mid+1 ;
    }  
    if (vec1[start]<=vec1[mid]){ // left sorted . 
        if(vec1[start]<=target && target<=vec1[mid]){
            end = mid -1 ; 
        }
        else{
            start = mid+1 ; 
        }
    }else{
        if(vec1[mid] <= target && target<= vec1[end]){
            start = mid + 1 ; 
        }
        else{
            end = mid -1 ; 
        }
    }
    }
 
}


int main(){

vector<int> vec1 ={3,4,5,6,7,0,1,2} ;
int sizee = vec1.size() ;
int target = 2 ;
cout<< Binarysearch_2(  vec1 ,  sizee ,  target) ;

return 0;
}