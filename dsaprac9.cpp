// Product of array except self -->

#include<iostream>
#include<iomanip>
#include<vector>

using namespace std;

int main(){
// Brute force approach -->

vector<int>vec1 = {1,2,3,4,5};
int n = vec1.size() ;
vector<int>ans( n , 1);

for (int i = 0  ; i < vec1.size() ; i++){
    int product = 1 ; 
    for (int j = 0 ; j < vec1.size() ; j++){
        if(j != i){
           ans[i] *= vec1[j] ; 
        } }  }
int k =0 ; 
while( k < 5){
 cout<<ans[k]<<" " ;
 k++ ;  
}
cout<<endl;
cout<<endl;


// Optimised method -->

vector<int>prefix( n , 1);
vector<int>suffix( n , 1);
vector<int>ans2( n , 1);

for (int i =0 ; i< n ; i++){
    prefix[i] = prefix[i-1]*vec1[i-1]; // Prefix claculation . 

}
for (int i = n-2 ; i>= 0 ; i--){
   suffix[i] = suffix[i+1] * vec1[i+1] ;//suffix claculation .  
}
for (int i = 0 ; i<n; i++){
    ans2[i]=prefix[i]*suffix[i]; //FInally storing the answer . 
}
int m =0 ; 
while( m < 5){
 cout<<ans[m]<<" " ;
 m++ ;  
}
cout<<endl;
cout<<endl;

// Most optimised form -->

int prefixx = 1 ; 
int suffixx = 1 ; 
vector<int>ans3( n , 1);
for (int i= 1 ; i<n ; i++){
    ans3[i] = ans3[i-1] * vec1[i-1] ; 
}
for (int i = n-2 ; i >= 0 ; i--){ // For suffix .
   suffixx *=  vec1[i+1] ; 
   ans3[i] *=  suffixx ; 
}
int na =0 ; 
while( na < 5){
 cout<<ans[na]<<" " ;
 na++ ;  
}
return 0;

}