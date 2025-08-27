// Knights Tour-->

#include<iostream>
#include<iomanip>
#include<vector>
using namespace std;
bool helper(vector<vector<int>> &grid , int r , int c , int n , int expval){
    if(r<0  || c<0 || r>= n || c>=n || grid[r] [c] != expval ){
        return false ;
    }
    if(expval == n*n-1){
        return true ;
    }

int ans1  = helper(grid , r-2 , c+1 ,n , expval+1) ; 
int ans2  = helper(grid , r-1 , c+2 ,n , expval+1) ; 
int ans3  = helper(grid , r+1 , c+2 ,n , expval+1) ; 
int ans4  = helper(grid , r+2 , c+1 ,n , expval+1) ; 
int ans5  = helper(grid , r+2 , c-1 ,n , expval+1) ; 
int ans6  = helper(grid , r+1 , c-2 ,n , expval+1) ; 
int ans7  = helper(grid , r-1 , c-2 ,n , expval+1) ; 
int ans8  = helper(grid , r-2 , c-1 ,n , expval+1) ; 

return ans1 || ans2 || ans3 || ans4 || ans5 || ans6 || ans7 || ans8 ;
} 

bool checkValidgrid(vector<vector<int>> grid){
return helper(grid , 0 , 0 , grid.size() , 0 );
}

int main(){
vector<vector<int>> grid = {
        {0, 3, 6},
        {5, 8, 1},
        {2, 7, 4}
    };

    if (checkValidgrid(grid)) {
        cout << "Valid Knight's Tour ✅" << endl;
    } else {
        cout << "Not a Valid Knight's Tour ❌" << endl;
    }
return 0;
}