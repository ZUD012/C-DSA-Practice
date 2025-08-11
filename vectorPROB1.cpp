// Given in a nin-empty array of integers nums , every element appears twicew except one find that one number (no use of nested loops) . 

#include<iostream>
#include<iomanip>
#include<vector>
using namespace std;

class Solution{

public :
int singleNUmber(vector<int> &nums){

//(using XOR)
int ans = 0 ; 
for(int i : nums){
    ans = ans ^ i ;
}
return ans ; 
 }
 
};
int main(){
vector<int>vec={4,2,4,5,5} ;
Solution obj ;
int unique = obj.singleNUmber(vec) ; 
cout<<"The unique number in the vector is : "<<unique ; 

return 0;
}