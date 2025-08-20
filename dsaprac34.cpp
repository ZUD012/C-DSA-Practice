// 3 SUM DSA -->
#include<iostream>
#include<iomanip>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

// Hashing ->
vector<vector<int>> Threesum(vector<int> &nums) {
    int n = nums.size();
    vector<vector<int>>ans ;
    set<vector<int>>uniquetriplets ;

    for (int i = 0 ;i<n ; i++){
        int tar = -nums[i] ;
        set<int> s ; 

        for (int j = i+1 ; j < n ; j++){
            int third = tar - nums[j] ;

            if(s.find(third) != s.end()) {
              vector<int> trip = {nums[i] , nums[j] , third};
              sort(trip.begin() , trip.end()); 
              uniquetriplets.insert(trip);
            }

            s.insert(nums[j]);
        }
    } 
}

// Two pointer approach ->
vector<vector<int>> Threesumm(vector<int> &nums){
  int n = nums.size() ;
  vector<vector<int>> ans ; 
  sort(nums.begin(),nums.end());

  for (int i =0 ; i<n ; i++){
    if(i > 0 && nums[i] == nums[i-1]){
        continue ;
    }
    int j =i+1 , k = n-1 ;
    while (j < k){
      int  sum = nums[i] + nums[j] + nums[k] ;
      if(sum < 0 ) {
        j++ ;
      }
      else if(sum > 0){
        k-- ;
      }
      else {
        ans.push_back({nums[i] , nums[j] , nums[k]}) ; 
        j++ , k-- ;

        while(j<k && nums[j] == nums[j-1]){
            j++ ;
        }
      }
    }
  }
   return ans; 
}

int main(){

vector<int>nums = {-1,0,1,2,-1,-4} ;
// Find unique Triplets ->
vector<vector<int>>ans = Threesumm(nums) ;

 cout << "Unique Triplets are:\n";
    for (auto &trip : ans) {
        cout << "[ ";
        for (int num : trip) cout << num << " ";
        cout << "]\n";
    }
return 0;
}