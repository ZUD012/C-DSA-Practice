// Count Inversion -->
#include <iostream>
#include <vector>
using namespace std;

int merge(vector<int> &arr, int st, int mid, int end) {
    vector<int> temp;
    int i = st, j = mid + 1;
    int invcount = 0;

    while (i <= mid && j <= end) {
        if (arr[i] <= arr[j]) {
            temp.push_back(arr[i]);
            i++;
        } else {
            temp.push_back(arr[j]);
            j++;
            invcount += (mid - i + 1); // all remaining elements in left part are greater
        }
    }

    while (i <= mid) {
        temp.push_back(arr[i]);
        i++;
    }
    while (j <= end) {
        temp.push_back(arr[j]);
        j++;
    }

    for (int idx = 0; idx < temp.size(); idx++) {
        arr[idx + st] = temp[idx];
    }

    return invcount;
}

int mergesort(vector<int> &arr, int st, int end) {
    if (st >= end) return 0;

    int mid = st + (end - st) / 2;
    int left_count = mergesort(arr, st, mid);
    int right_count = mergesort(arr, mid + 1, end);
    int invcount = merge(arr, st, mid, end);

    return left_count + right_count + invcount;
}

int main() {
    vector<int> arr = {6, 3, 5, 2, 7};
    int n = arr.size();

    int result = mergesort(arr, 0, n - 1);

    cout << "Number of Inversions = " << result << endl;
    return 0;
}
