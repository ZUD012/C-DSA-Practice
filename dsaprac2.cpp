//To find reverse of a number  . 
#include<iostream>
#include<iomanip>

using namespace std;


int reverse_number(int number) {
    int rev = 0;
    while (number > 0) {
        int digit = number % 10;
        rev = rev * 10 + digit;
        number /= 10;
    }
    return rev ;
}



//To finfd whether a number is power of 2  .

int main(){
    int digit ;
    cout<<"Enter the number to reverse : ";
    cin>>digit;
    cout<< reverse_number (digit) <<endl; 
  
    
    
       
    

return 0;
}