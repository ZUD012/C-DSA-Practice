// COMBINATION SUM .
#include<iostream>
#include<iomanip>
#include<vector>
using namespace std;

void helper(vector<int> &arr ,int idx ,int target ,vector<vector<int>>&ans , vector<int> &combination  ){

    if(idx == arr.size() || target < 0 ){
        return ; 
    }

    if (target == 0){
        ans.push_back(combination);
        return;
    }

    combination.push_back(arr[idx]);
    // Single
    helper(arr , idx , target-arr[idx] , ans , combination) ;
    combination.pop_back() ;
    //Exclusion
     helper(arr , idx+1 , target , ans , combination);
}





vector<vector<int>> combinationSum(vector<int> &arr , int target ){
vector<vector<int>>ans ;
vector<int>combination ; 
helper(arr , 0 , target , ans , combination) ; 
return ans ; 
}

int main(){
vector<int> arr = {2,3,5};
int target = 8 ;
vector<vector<int>>ans ;
vector<int>combination ; 
  vector<vector<int>> solution = combinationSum(arr , target );

    cout << "Combinations:\n";
    for (auto &row : solution){
        cout << "[ ";
        for (int num : row){
            cout << num << " ";
        }
        cout << "]\n";
    }
return 0;
}