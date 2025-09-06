#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<int> NextGreaterElement(vector<int> &nums) {
    int n = nums.size();
    vector<int> ans(n, -1); // Initialize with -1
    stack<int> s;

    // Traverse twice for circular behavior
    for (int i = 2 * n - 1; i >= 0; i--) {
        int index = i % n;
        while (!s.empty() && nums[s.top()] <= nums[index]) {
            s.pop();
        }
        if (!s.empty()) {
            ans[index] = nums[s.top()];
        }
        s.push(index);
    }
    return ans;
}

int main() {
    vector<int> nums = {1, 2, 1};
    vector<int> result = NextGreaterElement(nums);

    cout << "Next Greater Elements: ";
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
