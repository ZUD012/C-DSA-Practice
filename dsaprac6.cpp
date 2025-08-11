// Computing x^n using binary exponentiation -->
// Also used concept of decimal to binary conversion concept .  

#include<iostream>
#include<iomanip>

using namespace std;
// Binary exponentiation algorithm -->

// Decimal to binary form -->

int decimal_to_binary(int decnum){ // Finding the binary form of exponent . 
    
    int binform = 0 , pow  =  1 ;

    while(decnum > 0){
        int rem = decnum % 2 ;
        decnum /= 2 ;
        binform += (rem * pow);
        pow *=  10 ;
        } 
    return binform ;
    }
  


double  myPow(double x , int n ,  long binform  ){
// Here n is power of x .
// here 
    int decnum ;
 
     decimal_to_binary(x) ; 
    binform ;
    double ans = 1.0 ;
    if (n == 0) {
        return 1.0 ; 
    }
    if (x==0){
        return 0.0 ; 
    }
    if (n<0){
        x=1/x;
        binform = -binform ;   
    }
    while (binform > 0){
         if(binform %2 == 1 ){
            ans*= x ;
         }
         x*=x;
         binform /=10 ;

    }
    return ans ;
}
int main(){

int decnum ; 
int power ; 
cout<<"Enter the number of which you want to find binary form : ";
cin>>decnum ;
cout<<"enter the power : ";
cin>>power ;
cout <<"This is the binary form : "<< decimal_to_binary(power)<<endl  ;
long binform  = decimal_to_binary(power) ; 
cout<<"This is "<<decnum<<" ^ "<<power<<" =  "<<myPow(decnum  , power , binform ) ; 



return 0;
}