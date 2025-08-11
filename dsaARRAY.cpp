#include <iostream>
#include <iomanip>
#include <climits>
#include <algorithm>
using namespace std;

// linear search algorithm -->

int linearsearch(int arr[], int target, int size = 5)
{

    for (int i = 0; i < 5; i++)
    {
        if (arr[i] == target)
        {

            return i;
        }
    }
    return -1;
}

// Reversing the elements inside an array -->
int swapp(int &a, int &b)
{
    int temp1;
    temp1 = a;
    a = b;
    b = temp1;
    return a, b;
}
// using self made swap function ->

int reversing_the_element(int arr[], int size)
{
    int start = 0, end = size - 1;
    while (start < end)
    {
        swapp(arr[start], arr[end]);
        start++;
        end--;
    }
}



int main()
{

    // creating array -->
    int marks[5] = {99, 100, 35, 65, 88};

    double price[] = {98.99, 105.67, 30.00, 25.09, 31.03};

    // accessing data inside an array -->
    cout << marks[0] << endl
         << endl;
    // Using loop ->
    for (int i = 0; i < 5; i++)
    {
        cout << marks[i] << endl;
        cout << price[i] << endl;
    }
    cout << endl;
    cout << endl;

    // finding smallest value in array using loops ;

    int smallest = INT_MAX;
    int largest = INT_MIN;
    for (int i = 0; i < 5; i++)
    {
        if (marks[i] < smallest)
        {
            smallest = marks[i];
        }
    }
    int i = 0;
    for (int i = 0; i < 5; i++)
    {
        if (marks[i] > largest)
        {
            largest = marks[i];
        }
    }

    cout << "The smallest number is : " << smallest << endl;
    cout << "The largest number is : " << largest << endl;

    // understanding concept of min and max function .

    for (int i = 0; i < 5; i++)
    {

        smallest = min(marks[i], smallest);
        largest = max(marks[i], largest);
    }
    cout << "The smallest number is : " << smallest << endl;
    cout << "The largest number is : " << largest << endl;

    // Linear search algorithm ;
    int position = linearsearch(marks, 65, 5);
    if (position != -1)
    {
        cout << "Element " << marks[position] << " found at position : " << position + 1 << endl;
    }
    else
    {
        cout << "Element not found " << endl;
    }

    reversing_the_element(marks, 5);

    for (int i = 0; i < 5; i++)
    {
        cout << marks[i] << " ";
    }

    
    return 0;
}