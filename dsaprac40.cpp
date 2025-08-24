// N Queens
#include<iostream>
#include<iomanip>
#include<vector>
using namespace std;

bool isSafe(vector<string> &board , int row , int col , int n ){
// horizontal
for(int  j= 0 ; j<n ; j++ ){
    if(board[row][j]=='Q'){
        return false;
    }
}
//Vertical
for(int  j= 0 ; j<n ; j++ ){
    if(board[j][col]=='Q'){
        return false;
    }
}
//left diagonal
for(int  i= row , j =col ; i>=0 && j>=0 ; i-- , j-- ){
    if(board[i][j]=='Q'){
        return false;
    }
}
// Right diagonal
for(int  i= row , j =col ; i>=0 && j<n ; i-- , j++ ){
    if(board[i][j]=='Q'){
        return false;
    }
}
return true ; 
}

void nQueens(vector<string> &board , int row , int n ,vector<vector<string>> &ans) 
{
    if(row == n){
        ans.push_back(board) ; 
        return ; 
    }


    for(int j = 0 ; j<n ; j++){
      if(isSafe(board,row,j,n)){
        board[row][j] = 'Q' ;
        nQueens(board , row+1 , n ,  ans ) ;
        board[row][j] = '.' ;
      }
    }
}

vector<vector<string>> solveQueens(int n){
    vector<string> board(n,string(n,'.')); 
    vector<vector<string>> ans ; 
    nQueens(board , 0 , n , ans);
    return ans ;
}
int main(){
int n = 4;
vector<vector<string>> solutions = solveQueens(n);
 for(auto &board : solutions){
        for(auto &row : board){
            cout << row << "\n";
        }
        cout << "\n";
    }

return 0;
}