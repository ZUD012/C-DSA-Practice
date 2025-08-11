// To understand working of " pointers " and " address of operator " --> 

 #include<iostream>
 #include<iomanip>
 using namespace std;
 
// Understanding concept of pass by reference ->

 void change (int *g ){ // Pass by reference using pointers . 
    *g = 20 ; 
 }
 void change (int &j ){ // Pass by reference using pointers . 
    j = 20 ; 
 }

 int main(){ 
// address of operator -->
 int b  = 10 ;
 cout<<"Address of b : "<< &b <<endl ; 
 cout<<endl;
 cout<<endl;

// Understanding concept of pointers ->
int a  = 10 ;
int *ptr = &a ; 
cout<<"Adress of a using 'ptr' statement: "<<ptr<<endl; 
cout<<"Adress of a using '&a' statement: "<<&a<<endl; 
cout<<endl;
cout<<endl;

//Understanding concept of pointer to pointer concept ->

int m  = 10 ;
int *potr = &m ; 
int **parpoint = &potr ; 
cout<<"Printing adress  using 'parpoint' statement: "<<&m<<endl; 
cout<<endl ; 
cout<<endl ; 

// Understanding concept of dereferencing operator ->
cout<<"Printing value of 'a' using dereferencing operator : "<<*ptr<<endl; 
cout<<"Printing value of 'parpoint'(pointer to pointer) using dereferencing operator : "<<**parpoint<<endl; 

// Understanding concept of pass by reference ->
int g = 55 ; 
change(&g) ; 
cout<<"The value of a is : "<<g ;

int daca = 354 ; 
change(daca) ; 
cout<<"The value of a is : "<<g ;
cout<<endl;
cout<<endl;

// Array pointer ->
int array [4] = {1,3,4,5} ; 
cout<< array<<endl ; 
cout<<*array<<endl ; 
// Subtraction in pointers ->
int *ptr2 ; 
int *ptr1 = ptr2 + 2 ; 
cout<< ptr1 - ptr2 <<endl ;
return 0; 
 }