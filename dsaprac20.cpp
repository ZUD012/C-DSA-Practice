// Solving problems of array -->

#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <vector>

using namespace std;
// Merge two sorted array ->
void Merge_sorted_array(vector<int> &a, vector<int> &b, int m, int n)
{
    int idx = m + n - 1, i = m - 1, j = n - 1;

    while (i >= 0 && j >= 0)
    {
        if (a[i] >= b[j])
        {
            a[idx] = a[i];
            idx--, i--;
        }
        else
        {
            a[idx--] = b[j--];
        }
    }
    while (j >= 0)
    {
        a[idx--] = b[j--];
    }
}

// Next Permutation concept ->
// Return Lexicographically next ->


void nextPermutation(vector<int> &A) {
    int pivot = -1; 
    int n = A.size();

    // Step 1: Find pivot
    for (int i = n - 2; i >= 0; i--) {
        if (A[i] < A[i + 1]) {
            pivot = i; 
            break; 
        }
    }

    // Step 2: If no pivot, reverse entire array
    if (pivot == -1) {
        reverse(A.begin(), A.end());
        return;
    }

    // Step 3: Find next greater element and swap
    for (int i = n - 1; i > pivot; i--) {
        if (A[i] > A[pivot]) {
            swap(A[i], A[pivot]);
            break;
        }
    }

    // Step 4: Reverse suffix
    reverse(A.begin() + pivot + 1, A.end());
}




int main()
{
    vector<int> A = {1, 2, 3, 0, 0, 0};
    vector<int> B = {2, 5, 6};
    int m = 3, n = 3;
    
    Merge_sorted_array(A, B, m, n);
    for (int i = 0; i < 6; i++)
    {
        cout << A[i] << " ";
    }
   cout<<endl ; 

    //vector<int> a = {6,5,4,3,2,1};
   
    vector<int> my = {3, 2, 1 };
    nextPermutation(my);
    for (int x : my) cout << x << " ";
    return 0;
}