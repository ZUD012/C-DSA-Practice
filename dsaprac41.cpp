#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

bool issafe(vector<vector<char>> &board, int row, int col ,  char digit){   
// Horizontal ->
for(int j = 0 ; j < 9 ; j++){
    if(board[row][j]){
        if(board[row][j] == digit){
            return false ;
        }
    }
}

//  vertical check ->
for(int i = 0 ; i < 9 ; i++){
    if(board[i][col]){
        if(board[i][col] == digit){
            return false ;
        }
    }
}
// check inside the grid
int srow = (row/3) * 3;
int scol = (col/3) * 3;
for(int i=srow ; i<=srow+2 ; i++){
    for(int j = scol ; j<=scol+2 ; j++){
        if(board[i][j]==digit){
            return false ; 
        }
    }
}
return true ;
}



bool helper(vector<vector<char>> &board, int row, int col)
{ 
    if (row == 9){
      return true  ;
    }
    int nextrow = row, nextcol = col + 1;
    if (nextcol == 9)
    {
        nextrow = row + 1;
        nextcol = 0;
    }
    if (board[row][col] != '.')
    {
        return helper(board, nextrow, nextcol);
    }

    // place correct digit in the cell -->

    for (char digit = '1' ; digit <= '9' ; digit++)
    {
        if (issafe(board, row, col, digit))
        {
            board[row][col] = digit;
            if (helper(board, nextrow, nextcol))
            {
                return true;
            }
            board[row][col] = '.';
        }
    }
    return false;
}
void solve_Suduko(vector<vector<char>> &board, int row, int col)
{
    helper(board, 0, 0);
}
int main()
{
    vector<vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };

    solve_Suduko(board , 0 , 0);

    // Print solution
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}