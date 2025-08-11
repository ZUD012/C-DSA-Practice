// Sorting -  Bubble sort , selectionn sort , insertion sort -->
#include <iostream>
#include <iomanip>
#include <vector>
#include <utility>   // Used for swapping .
// swap can be used with both utility and algorithm . 

using namespace std;

// Bubble sort -> LOOP OF N-1 ;
void bubble_sort(vector<int> &vec1, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        bool isswap = false;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (vec1[j] > vec1[j + 1])
            {
                swap(vec1[j], vec1[j + 1]);
                isswap = true;
            }
        }
        if (!isswap)
        { // Array is slready sorted
            return;
        }
    }
}

 // Selection sort ->
    void selection_sort(vector<int> & vec1, int n)
{
        for (int i = 0; i < n; i++)
        {
            int s_i = i;
            for (int j = i + 1; j < n; j++)
            {
                if (vec1[j] < vec1[s_i])
                {
                    s_i = j;
                }
            }
            swap(vec1[i], vec1[s_i]);
     }
}

// Insertion sort ->
void insertion_sort(vector<int> & vec1, int n){
for (int i =  1 ; i < n-1 ; i++){
  int curr = i ;
  int prev = i-1 ; 
  while(prev >= 0 && vec1[prev] >curr){
    vec1[prev+1] = vec1[prev] ; 
    prev -- ;
  }
  vec1[prev+1] = curr ; // placing current element in its current position .
}
}

void print_vec1(vector<int> &vec1, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        cout << vec1[i] << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> vec1 = {4, 1, 5, 2, 3};
    int n = vec1.size();
    bubble_sort(vec1, n);
    cout<<"Using Bubble sort algorithm -->"<<endl ;
    print_vec1(vec1, n);
    cout<<endl;

    vector<int> vec2 = {12, 1, 5, 20, 13};
    selection_sort( vec2, n);
    cout<<"Using selection sort algorithm -->"<<endl ;
    print_vec1(vec2, n);
    cout<<endl;

    vector<int> vec3 = {13, 54, 5, 0, 12};
    insertion_sort( vec3,  n);
    cout<<"Using insertion sort algorithm -->"<<endl ;
    print_vec1(vec3, n);
    return 0;
}