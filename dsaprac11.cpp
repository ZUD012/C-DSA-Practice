// Binary search algorithm ->
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

// Binary search for searching element inside an vector ->

// Only applicable on sorted array or vector . 
int Binary_search(vector<int> &arr, int target)
{
    int n = arr.size();
    int start = 0;
    int end = n - 1;
    int ans;
    while (start < end)
    {
        int mid = start + (end - start) / 2; // TO secure you from integer overflow .
        if (target > arr[mid])
        {
            start = mid + 1;
        }
        else if (target < arr[mid])
        {
            end = mid - 1;
        }
        else
        {
            return mid;
        }
    }
}

// Binary search using recursion concept ->

int Binary_search_usingRecursion(vector<int> &vec1, int target, int start, int end)
{
    int mid = start + (end - start) / 2;
    if (start < end)
    {
        if (target > vec1[mid])
        {
            return Binary_search_usingRecursion(vec1, target, mid + 1, end);
        }
        else if (target < vec1[mid])
        {
            return Binary_search_usingRecursion(vec1, target, start, mid - 1);
        }
        else
        {
            return mid;
        }
        return -1;
    }
}
int main()
{

    vector<int> arr = {1, 4, 6, 7, 4, 8, 12};
    sort(arr.begin(), arr.end());
    int target;
    cout << "Enter the number you want to search : ";
    cin >> target;

    // Finding the number using normal binary method ->
    cout << "Answer using normal binary search : " << Binary_search(arr, target) << endl
         << endl;

    // Finding the number using recursive binary method ->
    int n = arr.size();
    int start = 0;
    int end = n - 1;
    cout << "Answer using recursion binary search : " << Binary_search_usingRecursion(arr, target, start, end);

    return 0;
}