#include<iostream>
#include<iomanip>
#include<vector>

using namespace std;

int main(){
vector <char> vec = {'n','m','k','u','f'};
vector <int> vect  (5,0); 

cout<<vec.size()<<endl;
cout<<vect.size()<<endl;
cout<<endl;
for(int i : vect){
    cout<<i<<endl;
}
for(char i : vec){
    cout<<i<<endl;
}
cout<<endl;
vec.push_back('m');

cout<<vec.size()<<endl;
cout<< vec.back()<<endl;
cout<< vec.front()<<endl;
cout<<vec.at(3);

// Finding the capacity of vector .

cout<<vec.capacity();
return 0;
}