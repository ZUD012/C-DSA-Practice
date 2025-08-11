#include<iostream>
#include<iomanip>
#include<vector>
using namespace std;

int main(){

vector<int>Big = {2,2,1,1,1} ; 
 
int length = Big.size() ; 
for (int i : Big){
   int frequency = 0 ; 
   for (int j : Big){
    if (j == i){
        frequency++;
    }
    if (frequency>length/2){
        cout<<"The number in majority is : "<<j<<endl;
    }
   }
}
return 0;
}