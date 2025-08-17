//2D Arrays in c++ -->

#include<iostream>
#include<iomanip>
#include<climits>
#include<vector>

using namespace std;


int diagonalSum(int mat[][3] , int n  ){
    int sum = 0;
    for (int i = 0 ; i < n ; i++ ){
        for (int j = 0 ;  j<n  ; j++){
            if (i == j ){
                sum +=mat[i][j] ;  
            }
            else if (j==n-i-1){
                sum += mat[i][j] ; 
            }
        } 
    }
    return sum ; 
}
int diagonalSumOPTIMISED(int mat[][3] , int n  ){
    int sum = 0;
    for (int i = 0 ; i < n ; i++ ){
        sum += mat[i][i];
        if (i != n-i-1){
            sum += mat[i][n-i-1]; 
        }
    }

    return sum ; 
}

int Find_max_sum(int mat[][3] , int row , int colms){
  int maxRowsum = INT_MIN ; 
  for (int i =0 ; i < row ; i++ ){
    int rowSum = 0 ;
    for(int j = 0 ; j < colms ; j++){
         rowSum+=mat[i][j] ;
    }
    maxRowsum = max(maxRowsum , rowSum);
  }
  return maxRowsum ;
}

bool linearsearch(int mat[][3] , int row , int colms , int key){
for(int i = 0 ; i < row ; i++){
for(int j = 0 ; j<row ; j++){
    if (mat [i] [j] == key) ; 
    return true ;
    
}
}

}

int main(){    
    // Finding whether an element is inside a matrixm -->

    int mat [3] [3] = {{1,2,3},{4,5,6},{7,8,9}} ; // 4 Rows 3 Coloumns ->
    int row = 3 ;
    int colms = 3 ;
    cout << Find_max_sum (mat,  row ,  colms)<<endl ;  // Finding the maximum sum by a row .
    cout << linearsearch (mat ,  row , colms , 8 )<<endl ; // searching whether an element is insude the matrix .
    cout << diagonalSum  (mat ,  3  )<<endl ;


    // Find The position of the matrix using concept of pair 

    int matrix [4] [3] ; // 4 Rows 3 Coloumns ->
    int rows = 4 ;
    int coloumns = 3 ;   
     matrix[2][1] = 18 ;   
    cout<<matrix[2][1]<<endl ; ; 

    // Loop For input ->

    for (int i  = 0 ; i < rows ; i++){
        for (int j = 0 ; j<coloumns ; j++){
            cin>>matrix[i] [j] ; 
        }      
    }

    // Loop For output ->

    for (int i  = 0 ; i < rows ; i++){
        for (int j = 0 ; j<coloumns ; j++){
            cout<<matrix[i] [j] <<" " ; 
        }
        cout<<endl ;
    }
  
    
    vector<vector<int>> mat = {{1,2,3},{4,5,6},{7,8,9}} ; 
return 0;
}