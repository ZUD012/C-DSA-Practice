// Important concepts and questions on string -->

#include<iostream>
#include<iomanip>
#include<string>
#include<cctype>
using namespace std;

//bool isAlphaNum(char ch){
//    if((ch>= '0' && ch<='9') || (tolower(ch)>= 'a' && tolower(ch) <='z')){
//        return true ; 
//    }
//    return false ;
//}

bool isAlphaNum(char ch) {
    return isalnum(ch); // Returns true if ch is a letter or digit
}
    
bool ispalindrome(string s ){
    int st = 0 ;
    int end = s.length()-1 ; 
    while(st<end){
        if(!isAlphaNum(s[st])){
            st++ ;
            continue ;
        }
        if(!isAlphaNum(s[end])){
            end-- ; 
            continue ;
        }
        if(tolower(s[st]) != tolower(s[end])){
            return false; 
        }
        st++ ; end-- ;
    }
    return true ;
}


// To remove all the occurance of string ->
string removeOccurances(string s , string part){
    while(s.length() > 0 && s.find(part)<s.length()){
        s.erase(s.find(part) , part.length()) ; 
    }
    return s ;
}
int main(){
// Valid palindrome ->
string s = "Ac3?e3c&a" ; 
if (ispalindrome(s)) {
    cout<<"Hence the Following string is palindrome ." ;
}
else{
    cout<<"Hence the following string is not a palindrome ." ;
}
cout<<endl ;
// c++ function which helps to identify whether a character is alphanumeric or not ->  isalnum(ch)

// Remove all occurances of string -->
string z = "daabcbaabcbc" ;
string part = "abc" ;

cout<<"The final string after the removing occurance is : "<<removeOccurances( z ,  part) ; 

return 0;
}