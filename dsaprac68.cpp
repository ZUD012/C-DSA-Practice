#include<iostream>
#include<algorithm>
#include<stack>
#include<vector>
using namespace std;

int largestRectangleArea(vector<int> &height) {
    int n = height.size();
    vector<int> left(n, 0);   // Nearest smaller to left
    vector<int> right(n, 0);  // Nearest smaller to right
    stack<int> s;

    // Find next smaller elements to the right
    for(int i = n - 1; i >= 0; i--) {
        while(!s.empty() && height[s.top()] >= height[i]) {
            s.pop();
        }
        right[i] = s.empty() ? n : s.top();
        s.push(i);
    }

    // Clear the stack before reuse
    while(!s.empty()) {
        s.pop();
    }

    // Find next smaller elements to the left
    for(int i = 0; i < n; i++) {
        while(!s.empty() && height[s.top()] >= height[i]) {
            s.pop();
        }
        left[i] = s.empty() ? -1 : s.top();
        s.push(i);
    }

    // Calculate the maximum area
    int ans = 0;
    for(int i = 0; i < n; i++) {
        int width = right[i] - left[i] - 1;
        int currarea = height[i] * width;
        ans = max(ans, currarea);
    }
    return ans;
}

int main() {
    vector<int> height = {2, 1, 5, 6, 2, 3};
    int result = largestRectangleArea(height);
    cout << "Largest Rectangle Area: " << result << endl;
    return 0;
}
