// Search in a 2D Matrix Optimised Approach -->
// Binary search .

#include<iostream>
#include<iomanip>
#include<vector>
using namespace std;


// Decreasing and sorted matrix ->
bool searchinrow(vector<vector<int>> &matrix , int target , int row){
int n = matrix[0].size();
int st =  0 , end = n-1 ;

while (st <= end ){
    int mid = st + (end - st)/2 ;
    if(target == matrix[row][mid]) {
        return true ; 
    }
    else if (target > matrix[row][mid]){
        st = mid + 1 ; 
    }
    else {
        st = mid - 1 ;  
    }

}
return false ; 
}

// Sorted But with diffrent pattern ->
bool searchMatrrix(vector<vector<int>> &matrix , int target){
    int m = matrix.size() , n = matrix[0].size() ;

    int r = 0 ;
    int c  = n -1  ;
    while(r < m && c  >= 0 ){
        if(target == matrix[r][c]){
            return true ; 
        }
        else if (target < matrix[r][c]){
            c-- ; 
        }
        else{
            r++ ;
        }
    }
    return false ; 
}

bool searchMatrix(vector<vector<int>> &matrix , int target){
    int m = matrix.size() , n = matrix[0] .size() ;
    int startrow = 0 ;
    int endrow = m-1 ;
    while(startrow<=endrow){
        int midRow = startrow + (endrow - startrow)/2 ;

        if(target >= matrix[midRow][0] && target<=matrix[midRow][n-1]){
            return searchinrow(matrix , target , midRow) ;  
        }
        else if(target >=  target<=matrix[midRow][n-1]) {
            startrow = midRow + 1 ;
        }
        else {
            endrow = midRow - 1 ;
        }
    }
    return false ;
}


int main(){
vector<vector<int>> matrix ={{1,3,5,7},{10,11,16,20},{23,30,34,60}};
int target = 30 ;

// Type 1 --> 
if (searchMatrix(matrix , target)) {
    cout<<"The target number is present inside the matrix  "<<endl ; 
}
else{
    cout<<"No similar element found inside the matrix  "<<endl ; 
}



// Type 2 -->

if (searchMatrix(matrix , target)) {
cout<<"The target number is present inside the matrix "<<endl ; 
}
else{
 cout<<"No similar element found inside the matrix  "<<endl ; 
}  

return 0;
}