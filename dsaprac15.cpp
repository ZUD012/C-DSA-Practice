// Book allocation Problem -->

// Refer to notebook to understand te question -->

// To find minimum possible maximum pages -->

// Sorted array not compulsory ; 
#include<iostream>
#include<iomanip>
#include<algorithm>
#include<vector>

using namespace std;
// The bool isvalid function helps us to compare whether distribution  possible while keeping mid value as maximumpages distributed . 
// It checks whethjer distribution is possible with the number of students i.e(m) . 
bool isvalid(vector<int> &vec1 , int n , int m , int maximum_allowed_pages/*(mid)*/ ) {
    int stud = 1 , pages = 0 ; 
    for (int i =0 ; i < n ; i++){
        if(vec1[i]>maximum_allowed_pages){
            return false ; 
        }
        if (pages+vec1[i]  <= maximum_allowed_pages ){
            pages+= vec1[i] ; 
        }
        else {
            stud++ ;
             pages =vec1[i] ; 
        }
    } 
    //return stud > m ? false : true ;  // stud > m -> invalid  -> false return 
                                      // stud <=m -> valid -> true return . 
    if (stud > m){
      return false ;
    }
    else return true ; 
    
}

int allocate_Book(vector<int> &vec1 , int n , int m){ // Here m is no. of students .and n is no. of books  .
    if (m>n){
      return -1 ; 
    }
  int  sum= 0 ;
  for(int i = 0 ; i<n ; i++){
    sum+= vec1[i] ; 
  }
int start = 0 ; 
int ans = -1 ; 
int end = sum ; // Range of possible answers . 

     while (start<=end) {
        int mid = start+ (end-start)/2 ;
        
        if (isvalid(vec1 , n , m , mid)){ /// Valid move left
             ans = mid ;
             end = mid - 1 ;

        }
        else{ // Invalid move Right
             start = mid+1 ; 
        }
     }
     return ans ; 
}

int main(){

vector <int> arr = {2,1,3,4} ;
vector <int> arr2 = {15,17,20} ;
int n = 4 ,  m = 2 ; 
int p = 3 ,  q = 2 ; 


// We cannot use binary search in arr as it is not compulsory that array is given sorted everytime .

// Find the range of answer ;

/*Minimum answer is 0 , 
Maximum answer is sum of all arrays i.e 10 ;
So now the range of our answer is = [0,1,2,3,4,5,6,7,8,9,10] . 

Now the Binary search algo. can be used as the array is sorted .(Time complexity[logn]) .
*/ 

cout<< allocate_Book(arr ,  n ,  m) <<endl; 
cout<< allocate_Book(arr2 ,  p ,  q)<<endl; 
return 0;
}