#include<iostream>
#include<iomanip>
#include<vector>
using namespace std;

int countPrime(int n ){
    vector<bool>isprime(n+1 , true) ; 
    int count = 0 ;

    for (int i = 0 ; i < n ; i++ ){
        if(isprime[i]) {
            count++ ;
            for (int j  = i*2 ; j <n ; j+ j+i ){
                isprime[j] = false ;
            }
        }
    }
    return count ; 
}

bool isArmstrong(int n){
  int CopyN = n ; 
  int SumOfCubes = 0 ;
  while(n != 0){
    int dig = n % 10 ;
    SumOfCubes += (dig*dig*dig) ;

    n = n/10 ; 
  }
  return SumOfCubes == CopyN ; 
}

int gcd (int a , int b){
while(a > 0 && b > 0){
    if(a > b){
        a = a%b;
        }
        else{
            b = b%a ; 
        }
}
   if ( a==0 ) return b ;
    return a ;
}


int main(){
int n = 153 ; 
if (isArmstrong(n)) {
    cout<<"Following is a Armstrong number "<<endl ;
} 
else{
    cout<<"Error"<<endl ; 
}

cout <<gcd ( 15 ,  12) ; 
return 0;
}