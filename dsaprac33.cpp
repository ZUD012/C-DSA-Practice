// Finding Duplicate -->

#include<iostream>
#include<iomanip>
#include<vector>

using namespace std;
int findDuplicate(vector<int> &nums){
    int slow = nums[0],fast = nums[0];
    do{
        slow = nums[slow] ; //+1
        fast = nums[nums[fast]];
    }while(slow != fast);
    slow = nums[0] ;
    while(slow != fast){
        slow = nums[slow];
        fast = nums[fast];
    }
    return slow ; 

}
int main(){
vector<int> nums = {1,3,4,2,2};
cout<<findDuplicate(nums)<<endl ;

return 0;
}