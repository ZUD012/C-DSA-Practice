#include<iostream>
#include<iomanip>
#include<vector>
#include<algorithm>
using namespace std;
vector<vector<int>> foursum(vector<int> &nums , int target){
    vector<vector<int>> ans ;
    int n = nums.size() ;

    sort(nums.begin() , nums.end());
    for(int i = 0 ; i<n ; i++){
        if  (i>0 && nums[i] == nums[i-1]) {
            continue ;
        }
        for(int j = i+1 ; j<n ;){

            int p = j+1 ;
            int q = n-1 ;
            while(p < q ){
                long long sum = (long long)nums[i] + (long long) + nums[j]+(long long)nums[p] + (long long) nums[q] ;
            
                if (sum < target){
                    p++ ;
                }else if (sum> target){
                    q-- ;
                }
                else{
                    ans.push_back({nums[i],nums[j],nums[p],nums[q]});
                    p++ ;
                    q-- ;
                    while(p<q && nums[p]== nums[p-1]){
                        p++ ;
                    }
                }
            }
            j++ ;
            while(j < n && nums[j] == nums[j-1]){
                j++;
            }
        }
    }

    return ans ;
}

int main(){
vector<int>nums = {-2,-1,-1,1,1,2,2};
int target =  6 ; 
vector<vector<int>> ans =foursum(nums ,  target);
cout << "Unique Triplets are:\n";
    for (auto &trip : ans) {
        cout << "[ ";
        for (int num : trip) cout << num << " ";
        cout << "]\n";
    }
return 0;
}