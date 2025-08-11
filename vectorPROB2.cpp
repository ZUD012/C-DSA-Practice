//Solving reversing and linear search in vectors ---->

#include<iostream>
#include<iomanip>
#include<vector>
#include<algorithm>
using namespace std;



//Functions for swapping in vectors -->
int swapp(int &a  ,  int &b ){
int temp = a ; 
a = b ;
b = temp ; 
}
void reversing_vector(vector<int> &vec ,int size ){
    int start = 0  ,  end = size - 1  ; 
    while(start<end){
        swapp(vec[start] , vec[end]);
        start++ ; 
        end--;
    }
}


//Function for linear search in vector -->
template<class t1 = int>
int vector_search(vector<int>vec , int target , int size){
    
    for (int i = 0 ; i< size ; i++){
        if (vec[i] == target) { 
        return i ;
    }}
    return -1 ; 
}

int main(){
vector<int>vec = {10 , 20 , 22 , 33 , 44 } ; 
int size = vec.size() ;
cout<<"Enter the number to search in the vector : " ;
int target ;
cin>> target ; 
int finder = vector_search(vec , target , size) ; 
if (finder != -1) {
    cout<<"Element "<<target<<" found in position "<<finder + 1  <<endl; 

}

reversing_vector(vec , size) ; 
for(int i = 0  ;  i< size  ; i++){
    cout<<vec[i]<<" " ; 
}

return 0;
}