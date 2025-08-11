// Single element in sorted array -->

// All the elements occur twice except one element inside an array .

// Using binary search ->
#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

int Binary_search_4(vector<int> &vec1)
{
    int start = 0;
    int sizee = vec1.size();
    int end = sizee - 1;
    int mid;
    while (start <= end)
    {

        mid = start + (end - start) / 2;
        if (mid ==0 && vec1[0] != vec1[1]){
            return vec1[0] ; 
        }
        if (mid == vec1[sizee-1] && vec1[sizee-1]!=vec1[sizee-2]){
            return vec1[sizee-1];
        }
        if (vec1[mid] != vec1[mid-1] && vec1[mid] != vec1[mid+1]){
            return vec1[mid] ;
        }
        if (mid % 2 == 0) // To check whether elements in vector are odd or even numbers .
        {
            if (vec1[mid] == vec1[mid - 1])
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        else{
            if (vec1[mid]== vec1[mid-1]){
                start = mid + 1 ;
            }
            else{
                end = mid -1 ;
            }
        }
    }
    
}
int main()
{
    vector<int> vec1 = {1, 1, 2, 3, 3, 4, 4, 8, 8}; // If mid is even .
    vector<int> vec2 = {3, 3 , 7 , 7, 11,  11, 1};    // If mid is odd .
     
    cout<<"The single diffrent element for following array with  even mid value : "<<Binary_search_4(vec1)<<endl ;
    cout<<"The single diffrent element for the following array with odd mid value : "<<Binary_search_4(vec2)<<endl ;
    return 0;
}