// Permutations in array -->
#include<iostream>
#include<iomanip>
#include<vector>
#include<algorithm>
using namespace std;
void getperm(vector<int> &nums , int idx, vector<vector<int>> &ans){
     if(idx == nums.size()){
        ans.push_back(nums);
        return ;
    }
   for (int i = idx ; i< nums.size() ; i++){
    
    swap(nums[idx],nums[i]); // idx place --> 1st element choice .
    getperm(nums , idx+1 , ans); 
    swap(nums[idx] , nums[i]) ; 
   }

}

vector<vector<int>>permutation(vector<int> &nums  ){
   vector<vector<int>> ans ;
   getperm(nums,0,ans) ; 

   return ans ;
}

int main(){
vector<int> nums ={1,2,3} ;
permutation(nums );
vector<vector<int>> allPerms = permutation(nums); 
     for (auto &subset : allPerms) {
        cout << "[ ";
        for (int x : subset) cout << x << " ";
        cout << "]\n";
    }
return 0;
}