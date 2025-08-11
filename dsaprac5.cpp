//Finding element in majority  in an array  -->

#include<iostream>
#include<iomanip>
#include<vector>
#include<algorithm>
using namespace std;


//Finding element in majority  in an array using brute force approach -->

int Finding_major(vector<int> &m , int size){
int*ptr ; // setting up a  pointer as we don't want to return just value we need  to print the answer . 
//-> We use ranged based for loop here to get acces of the element not its position . 
for (int i : m){ // i here is the vlaue of element not the position of element . 
   int frequency = 0 ; // ptr is a pointer here .
   for (int j : m){
    if (j == i){
        frequency++;
    }
    if (frequency>size/2){
         ptr = &i ;
    }
    
   }
   
}

cout<<"\nThe element in majority is : "<<*ptr ; 
}


// Boyer-Moore Voting Algorithm -->
// {1,2,1,1,2}
int majority_element(vector<int> b , int size){
    int freq = 0 ;
    int ans  = 0 ;
    for (int i = 0 ; i<size ; i++){
        if (freq == 0 ){ // A bit heavy logic . 
           ans = b[i];
        }
        if (ans == b[i]){
            freq ++;
        }
        else{
            freq -- ; 
        }
    }
    cout<<"Number in majority by ( Boyer - moore voting algorithm is ) : "<< ans ; 
}

int main(){

vector<int> nums  = {2,7,8,15} ;
int c = nums.size() - 1 ;

// Brute force approach -->

    int target ; 
    cout<<"Enter the desired sum you want : ";
    cin>>target ; 

vector<int> ans ;
vector<int> an ;
for (int i = 0 ; i < nums.size() ; i++){
    for(int j = i+1  ; j< nums.size() ; j++){
        if  (nums[i] + nums[j] == target)  {
           ans.push_back(i) ; 
           ans.push_back(j) ;
          
        }

    }
}
for(int k = 0  ; k < ans.size() ; k++){
    cout<<ans[k]<<" " ; 
}


// Optimised form (Two pointer approach) -->

int m = 0 , n = c ; 

while(m<n){
    int pairsum = nums[m] + nums[n] ;
    if(pairsum > target){
        n--;
    }
    else if (pairsum <target){
        m++ ;
    }
    else{
        an.push_back(m);
        an.push_back(n);
        break ; 
    }
    
}
cout<<endl;


for(int p = 0  ; p < ans.size() ; p++){
    cout<<an[p]<<" " ; 
}

// Finding majority element inside an array which occupies more than half space in an array (frequency greater than n/2) -->
//Using brute force approach ->
//in this case one array(major)occupies more than half of the array

vector<int>Big = {1,2,1,1,2} ; 
 
int length = Big.size() ; 
Finding_major(Big , length ) ;
cout<<endl;

// Finding major element using moore's voting algorthm -->

majority_element(Big , length) ; 





return 0;
}