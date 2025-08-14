// Permutation in strings -->
#include<iostream>
#include<iomanip>
#include<string>
using namespace std;

bool isFreqsame(int freq1[] , int freq2[]){
    for (int i=0 ; i<26 ; i++){
        if(freq1[i] != freq2[i]){
            return false ;
        }
    }
    return true ; 
}

bool CheckInclusion(string s1 , string s2){
int freq[26] = {0} ;
for (int i = 0 ; i<s1.length() ; i++){
    int idx = s1[i] - 'a' ; // Both gets converted into ascii values . // so a-> 0 , b-> 1 , c -> 2 ... ->
    freq[idx]++ ; 
}

int windsize = s1.length() ;

for (int i  = 0 ; i<s2.length() ; i++){
    int Winidx = 0 , idx = i ;
    int Windfreq[26] = {0} ; 

    while(Winidx < windsize && idx < s2.length()){
            Windfreq [s2[idx]-'a']++ ;
            Winidx++ , idx++ ; 
    }
    if(isFreqsame(freq , Windfreq)){
        return true ;
         
    }
}
return false ; 

}

int main(){
string s1 = "ab" ;
string s2 = "eidbamooo" ;
if(CheckInclusion( s1 ,  s2)){
    cout<<"Value exists" ;
} 
else{
    cout<<"No value exists" ;
}
cout<<endl;

int freq[26] = {0,2,3,5,4} ;
for (int i = 0 ; i<4 ; i++){
    int idx = s1[i] - 'a' ; // Both gets converted into ascii values . // so a-> 0 , b-> 1 , c -> 2 ... ->
    freq[idx]++ ; 
    cout<<*freq ;
}
return 0;
}