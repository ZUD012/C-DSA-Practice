// Reverse words in string -->
//AlphaNumericValue ->
#include<iostream>
#include<iomanip>
#include<string>
#include<algorithm>
using namespace std;

string reverseWords(string &s ){
    int n = s.length();
    string ans = "" ;
    reverse(s.begin() , s.end()) ; //  Reverse each element of entire string .

    for (int i = 0 ; i< n ; i++ ){   // This loop helps to identify words in sentence and then reverse them to make appropriate word .
        string word = "";
        while(i < n && s[i] != ' '){
            word += s[i] ;
            i++ ; 
        }
        reverse(word.begin() , word.end());
        if(word.length() > 0){
           ans += " " + word ;
        }
    }
    return ans.substr(1);
}
int main(){

string s1 = "The sky is blue";
string s2 = "Hello World";
cout<<reverseWords( s1 )<<endl;
cout<<reverseWords( s2 )<<endl ;

return 0;
}