#include<iostream>
#include<iomanip>
using namespace std;

// Decimal to binary .   
int decimal_to_binary(int decnum){
    int ans = 0 , pow  =  1 ;

    while(decnum > 0){
        int rem = decnum % 2 ;
        decnum /= 2 ;
        ans += (rem * pow);
        pow *=  10 ;
    }
    return ans ;   
}

// Binary to deciaml .
int binary_to_decimal(int binum){
int ans =0  ,  pow  =  1  ; 
while (binum > 0){
    int rem =  binum % 10 ; // helps to get the last number of the binary . 
    ans += rem * pow ;
    binum /= 10 ; 
    pow*= 2 ;     
}
return ans ;  // Decimal form
}
int main(){
cout<<"Press 'a' to convert BINARY TO DECIMAL and press 'b' to convert DECIMAL TO BINARY --> ";
char intake  ; 
cin>>intake ;
if (intake == 'a'){  
int number;
cout<<"Enter the number to find its binary form : ";
cin>>number;   
cout << decimal_to_binary(number); 
}

else {
int number;
cout<<"Enter the number to find its decimal form : ";
cin>>number;   
cout << binary_to_decimal(number) ; 
}

return 0;
}