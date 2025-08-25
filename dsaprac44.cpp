// Plindrome Partioning 
#include<iostream>
#include<iomanip>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;


bool ispalin(string s){
string s2 = s  ;
reverse(s2.begin(),s2.end());
return s == s2 ; 
}

void getAllparts(string s , vector<string> &partition , vector<vector<string>>&ans){
     if(s.size() == 0){
        ans.push_back(partition);
        return ;
     }
for(int i =0 ; i<s.size() ; i++){
    string part = s.substr(0,i+1) ;

    if(ispalin(part)){
        partition.push_back(part);
        getAllparts(s.substr(i+1), partition, ans);
        partition.pop_back();
    }
}

}


vector<vector<string>> partition(string s){
    vector<vector<string>> ans ;
    vector<string> partition ; 

    getAllparts(s,partition, ans ) ;
    return ans ; 
} 

int main(){
 string s = "aab";
    vector<vector<string>> res = partition(s);

    cout << "Palindrome Partitions of " << s << ":\n";
    for (auto &vec : res) {
        cout << "[ ";
        for (auto &str : vec) {
            cout << str << " ";
        }
        cout << "]\n";
    }
return 0;
}