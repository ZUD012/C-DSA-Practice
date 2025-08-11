// To find whether a number is power of 2  ; 
#include<iostream>
#include<iomanip>
using namespace std;

int  check_power(int number){
   bool check  = false ;   
    for (int i = 1 ; i <= number ; i*=2   ){
        
        if (i == number) {
          cout<<"Following number is  the power of 2 "<<endl;
          check = true ; 
         }}
        if (!check){
            cout<<"Following number is not the power of 2 "<<endl;
        }
}

int main(){
    
  int a ;
    cout<<"Enter a number to check whether it is a power of 2 : ";
    cin>> a ;
    check_power(a);
     
return 0;
}