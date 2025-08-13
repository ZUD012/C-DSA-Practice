// Understanding concept of strings -->
#include<iostream>
#include<iomanip>
#include<string>
#include<algorithm>
using namespace std;

int main(){
string a = "Kamaldeep singh " ; // Dynamic in nature => runtime resize ;  
cout<< a << endl  ;    
string b = "Sahi aadmi hai " ;
cout << b <<endl  ; 
string c  =  a +  b ; // Concatigation ;
cout<< c <<endl ; 


// Reverse a string ->
string am = "Kamaldeep singh " ;
reverse(am.begin() , am.end()) ;
cout<<am ; 

return 0;
}