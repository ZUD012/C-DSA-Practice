// Container with most water -->

#include<iostream>
#include<iomanip>
#include<vector>
#include<algorithm>

using namespace std;

// Brute force approach -->

void container_withMostWater_1(vector<int> vec1 , int size){
 int maximum = 0 ; 
 int answer = 0 ; 
for (int first = 0 ; first < size  ; first++){
   
    for (int second = first + 1 ; second < size ; second++ ){
        int width = second - first ; 
        int height = min(vec1[first] , vec1[second]) ;
        int volume = width * height ;
        answer =  max(volume , answer) ; 
    } 
}
cout<<"The maximum amount of water which can be stored inside the containers is : "<<answer<<" litres"; 
}

//Two pointer approach -->

void container_withMostWater_2(vector<int> vec , int size){
    int start = 0 ; 
    int last = size - 1 ;
    int volume = 0 ; 
    int answer = 0 ; 
       while(start < last){
          int width = last - start;
          int height = min(vec[start] , vec[last]);
          int volume = (width * height) ; 
          if (vec[start] > vec[last]){
            last-- ; 
          }
          else{
            start++ ;
          }
           answer = max(answer , volume); 
       }
       cout<<"The maximum amount of water two containers can hold in the following given array is : "<<answer<<" litres"<<endl ; 
}

int main(){
vector<int> vec1 = {1,8,6,2,5,4,8,3,7} ; 
int sizee = vec1.size() ;

/*Brute-force approach -->*/ container_withMostWater_1( vec1 , sizee);

cout<<endl ; 
container_withMostWater_2( vec1 ,  sizee) ; 
return 0;
}