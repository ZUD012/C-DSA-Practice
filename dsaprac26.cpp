#include<iostream>
#include<iomanip>
#include<string>
#include<vector>
using namespace std;
int compress(vector<char> &chars){
 int n  = chars.size() ;
 int idx = 0 ;

 for (int i = 0 ; i < n ; i++){
    char ch = chars [i] ;
    int count = 0 ; 

    while(i < n && chars[i] == ch ){
        count++ ;
        i++ ; 
    }
    chars[idx++] = ch ; 
    
    if(count >1 )
    {
          string str = to_string(count);
          for(char dig : str){
            chars[idx++] = dig ;
          }
     }
     i-- ;
  }
  chars.resize(idx) ; 
  return idx ; 
}


int main(){
vector<char>chars = {'a','a','b','b','c','c','c'} ;
cout <<  compress(chars) ; 

return 0;
}