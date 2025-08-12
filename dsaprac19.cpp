// Sort array with 0s , 1s & 2s -->

#include<iostream>
#include<iomanip>
#include<vector>
#include<algorithm>
using namespace std;

// Optimised approach ->

void sort_Numbers(vector<int> &nums){
    int n = nums.size();
    int count0 = 0 , count1 =0 , count2 = 0 ;

    for (int i =0 ; i<n ; i++){
      if (nums[i] == 0) count0 ++  ;
      else if (nums[i] == 1) count1 ++  ;
      else  count2 ++  ;
    }

    int idx = 0 ;
    for (int i = 0 ; i < count0 ; i++ ){
        nums[idx++] = 0 ; 
    }
    for (int i = 0 ; i < count1 ; i++ ){
        nums[idx++] = 1 ; 
    }
    for (int i = 0 ; i < count0 ; i++ ){
        nums[idx++] = 2 ; 
    }
}

// Most optimal approach -> (Dutch national flag algorithm) 
void sort_Numbers_optimised(vector<int> &nums){

int n = nums.size()  ;
int low = 0 , mid = 0 , high = n-1 ; 
while(mid <= high){
    if (nums[mid] == 0) //0
    {
    swap(nums[low] , nums[mid]) ;
    mid ++ ; 
    low ++ ;
    }
    else if (nums[mid] ==1 ) //1
    {
      mid ++ ;
    }
    else { //2
      swap(nums[high] , nums[mid]) ; 
      high -- ;
    }
}
}
int main(){
vector <int> vec1  = {2,0,2,1,1,0,1,2,0,0} ;
 sort_Numbers(vec1) ; 
for (int i =0 ; i <10 ; i++){
    cout<<vec1[i]<<" " ; 

}
cout<<endl;
vector <int> vec2  = {2,0,1,2,1,0,1,0,2,0} ;
sort_Numbers_optimised(vec2) ;
for (int i =0 ; i <10 ; i++){
    cout<<vec2[i]<<" " ; 

}
return 0;
}