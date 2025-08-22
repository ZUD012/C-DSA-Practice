#include<iostream>
#include<iomanip>
#include<vector>
#include<algorithm>
using namespace std;

void printSubset(vector<int>&arr ,vector<int>&ans,int i ){
    if ( i == arr.size()){
    for (int j : ans){
        cout<<j<<" " ; 
    }
    cout<<endl ;
    return ;
    }
    ans.push_back(arr[i]);
    printSubset(arr,ans,i+1);

    ans.pop_back();
    printSubset(arr,ans,i+1);

}


void printSubset_2(vector<int>&arr ,vector<int>&ans,int i,vector<vector<int>> &allSubsets){

    if ( i == arr.size()){
    allSubsets.push_back(ans);

    return ;
    }
    ans.push_back(arr[i]);
    printSubset_2(arr,ans,i+1,allSubsets);

    ans.pop_back();
    int idx = i+1 ;
    while(idx<arr.size() &&arr[idx]==arr[idx-1]){
        idx++ ; 
    }
    printSubset_2(arr,ans,idx,allSubsets);

}
vector<vector<int>> subsetWithDup(vector<int> &nums){
    sort(nums.begin(),nums.end());
    vector<vector<int>> allsubset;
    vector<int> ans;

    printSubset_2(nums , ans , 0 ,allsubset) ; 
    return allsubset ; 
}


int main(){
vector<int> arr = {1,2,3,3} ; 
vector<int> ans  ; 

printSubset(arr ,ans, 0 );
cout<<endl ;
// Print result
     vector<vector<int>> res = subsetWithDup(arr); 
    for (auto& subset : res) {
        cout << "[ ";
        for (int x : subset) cout << x << " ";
        cout << "]\n";
    }
return 0;
}