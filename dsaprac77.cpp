// Sliding Window Maximum -->
#include <iostream>
#include <deque>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> rs;
        deque<int> dq;

        // Process first window
        for (int i = 0; i < k; i++) {
            while (!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
        }

        // Process the rest of the windows
        for (int i = k; i < nums.size(); i++) {
            // Record the max for the previous window
            rs.push_back(nums[dq.front()]);

            // Remove indices that are out of the current window
            while (!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }

            // Remove all elements smaller than the current one from the back
            while (!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }

            dq.push_back(i);
        }

        // Add the max for the last window
        rs.push_back(nums[dq.front()]);
        return rs;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;

    vector<int> result = sol.maxSlidingWindow(nums, k);

    cout << "Sliding window maximums are : ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
