//Pattern creations in dsa -->

#include<iostream>
#include<iomanip>
using namespace std;

/*
Pattern 1 -->
1234
1234
1234
1234
1234
*/
void Pattern_1 (int n , int m  ) {
    for (int i = 0 ; i < n ; i++){
       for (int j = 1 ; j < m ; j++ ){
           cout<<j<<" " ;
       }
        cout<<endl ; 
    } 
}

/*
Pattern 2 -->
123
456
789
*/

void Pattern_2 (int n , int m  ) {
    int count = 1 ;
    for (int i = 0 ; i < n ; i++){
       for (int j = 1 ; j < n ; j++ ){
           cout<<count++<<" " ;
       }
        cout<<endl ; 
    } 
}

/*
Pattern 3 -->
print star pattern 1 ->
*
**
***
**** 
*/

void Pattern_3 (int n , int m  ) {
    for (int i = 0 ; i < n ; i++){
        int j = 0 ;
       while(j <= i ){
           cout<<j<<" " ;
           j++ ; 
       }
        cout<<endl ; 
    } 
}

/*
Pattern 4 -->
print triangle pattern 1 ->
1
22
333
4444
55555
*/

void Pattern_4 (int n , int m  ) {
    for (int i = 1 ; i < n ; i++){
        int j = 1 ;
       while(j <= i ){
           cout<<i<<" " ;
           j++ ; 
       }
        cout<<endl ; 
    }
 }

/*
Pattern 5 -->
print triangle pattern 1 ->
1
12
123
1234
12345
*/

void Pattern_5 (int n , int m  ) {
    for (int i = 1 ; i < n ; i++){
        int j = 1 ;
       while(j <= i ){
           cout<<j<<" " ;
           j++ ; 
       }
        cout<<endl ; 
    } 
}


/*
Pattern 6 -->
print  triangle pattern 1 ->
1
21
321
4321
54321
*/

void Pattern_6 (int n , int m  ) {
    for (int i = 1 ; i < n ; i++){
        int j = 1 ;
       while(j <= i ){
           cout<<j<<" " ;
           j++ ; 
       }
        cout<<endl ; 
    } 
}
/*
Pattern 7 -->
print reverse triangle pattern 1 ->
1111
 222
  33
   4
*/

void Pattern_7 (int n , int m  ) {
    for (int i = 0 ; i < n ; i++){
        
       for(int j = 0 ; j < i ; j++){
            cout<<" " ; 
       }
       for (int j = 0 ; j<n-i ; j++){
        cout<<(i+1)<<"" ;
       }
        cout<<endl ; 
    } 
}

/*
Pattern 8 -->
Print Pyramid->
   1
  121
 12321
1234321
*/

void Pattern_8 (int n , int m  ) {
   for (int i = 0 ; i<n ; i++){

       for(int j = 0 ;  j <n-i-1 ; j++ ){
        cout<<" " ;
       }
       for(int j = 1 ; j<=i+1 ; j++){
        cout<<j;
       }
       for(int j = i ; j>=1 ; j--){
        cout<< j ;
       }
       cout<< endl ;
   }
}


/*
Pattern 9 -->
Print Pyramid->
  * 
*   *
  *
*/

void Pattern_9 (int n , int p = 4  ) {
for(int i = 0 ; i<p ; i++){
    for(int j = 0 ; j < p-i-1 ; j++){
        cout<<" " ;
    }
    cout<<"*" ;
    
    if(i!= 0){
         for(int j = 0 ; j<2*i-1 ; j++){
        cout<<" " ;
    }
        cout<<"*" ;
    }
    cout<<endl ;
}
// Bottom part ->
for(int i = 0 ; i<p-1 ; i++){
   
    for(int j = 0 ; j < i+1 ; j++){
        cout<<" " ;
    }

    cout<<"*";

    if (i != p-2){
        for(int j = 0 ; j < 2*(p-i-2)-1 ; j++){
        cout<<" " ;
    }
        cout<<"*" ;
    }
    cout<<endl ;
}
}

int main(){

int n = 8 ;
int m = 5 ;

Pattern_1 ( n , m ) ;

cout<<endl ;
cout<<endl ;

Pattern_2 ( n , m ) ;

cout<<endl ;
cout<<endl ;

Pattern_3 ( n ,  m  ) ;

cout<<endl ;
cout<<endl ;

Pattern_4 ( n ,  m  ) ;

cout<<endl ;
cout<<endl ;

Pattern_5 ( n ,  m  ) ;

cout<<endl ;
cout<<endl ;

Pattern_6 ( n ,  m  ) ;

cout<<endl ;
cout<<endl ;

Pattern_7 ( n ,  m  ) ;

cout<<endl ;
cout<<endl ;

Pattern_8 ( n ,  m  ) ;

cout<<endl ;
cout<<endl ;

Pattern_9 ( n ,  m  ) ;



return 0 ;
}