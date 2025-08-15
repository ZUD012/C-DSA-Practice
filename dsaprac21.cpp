// Understanding character array  -->  

#include<iostream>
#include<iomanip>
#include<string>
#include<cstring>
#include<string.h>// to use strlen() function . 
using namespace std;

int main(){
// Concept of  Character array ->
char str[] = {'a' , 'b' , 'c' , 'd'} ; 
cout<< str <<endl ;
char st[] = {'a' , 'b' , 'c' , 'd' , '\0' } ; 
cout<< st <<endl ;
cout<<strlen(st) ;
cout<<endl ;
char string[] = "Hello" ; // string literals .
cout<<string ;
char strings[] = "Hello" ; // string literals .
cout<<endl<<strings[4];
cout<<endl;


// concept  ->
char a [25] ;

//cout<<"Enter char array : "<<endl;
//cin>> a ; // If we leave a space betweent two words then the first word is only printed .

// Therefore specially for strings we use getline Function . 
// getline(cahar array name , no. of characters , delimiters) 

//cin.getline(a , 25 , '.') ;// Takes iput for a single line when the line changes it stops taking output . 
// Delimiter is a specifit character from where we wqant to stop taking input in getline function . 

//cout<<"Output : "<< a <<endl ; 

// TO print all characters of string a ->
//for(char ch : a){
//    cout<< ch << " " ; 
//}

// TO get length of a stence or a word in c++ ->
char ex1 [] = "Kapil Kumar" ; 
int len = 0 ; 
for (int i = 0 ; i < ex1[i] != '\0' ; i++){
len ++ ;
}
cout<<"The length of string is : "<<len ;





return 0;
}