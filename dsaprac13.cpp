// Peak index in mountain array -->

// Using Binary search approach ->

// Strictly increases till peak point after the peak point the value decreases ->
#include<iostream>
#include<iomanip>
#include<vector>

using namespace std;
int Binary_search_3(vector<int> &vec1 , int sizee){
    int start=1 ; // As answer cannot be first value . 
    int end = sizee - 2 ;  // As answer cannot be last value . 
    while(start<=end){
        int mid = start + (end - start) / 2 ;
        if (vec1[mid] > vec1[mid-1] && vec1[mid] > vec1[mid+1]){
            return mid+1  ;
        }
        if (vec1[mid] > vec1[mid-1]){  
            start = mid+1 ; 
        }
        else{
            end = mid -1 ; 
        }
    }
}

int main(){

vector<int>vec1={0,3,8,9,5,2};
int sizee = vec1.size() ;

cout <<"Hence the peak value in the following vector is at position : "<< Binary_search_3( vec1 ,  sizee) ; 
return 0;
}