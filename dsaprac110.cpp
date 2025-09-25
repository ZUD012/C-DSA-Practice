#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    // BFS to check rotting process
    void check_rotting(vector<vector<int>>& grid, vector<vector<bool>>& check, int n, int m, int &ans) {
        queue<pair<pair<int, int>, int>> Q;

        // Push all rotten oranges initially
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    Q.push({{i, j}, 0});
                    check[i][j] = true;
                }
            }
        }

        // BFS traversal
        while (!Q.empty()) {
            int i = Q.front().first.first;
            int j = Q.front().first.second;
            int time = Q.front().second;
            ans = max(ans, time); // track max time
            Q.pop();

            // Up
            if (i - 1 >= 0 && !check[i - 1][j] && grid[i - 1][j] == 1) {
                Q.push({{i - 1, j}, time + 1});
                check[i - 1][j] = true;
            }
            // Down
            if (i + 1 < n && !check[i + 1][j] && grid[i + 1][j] == 1) {
                Q.push({{i + 1, j}, time + 1});
                check[i + 1][j] = true;
            }
            // Left
            if (j - 1 >= 0 && !check[i][j - 1] && grid[i][j - 1] == 1) {
                Q.push({{i, j - 1}, time + 1});
                check[i][j - 1] = true;
            }
            // Right
            if (j + 1 < m && !check[i][j + 1] && grid[i][j + 1] == 1) {
                Q.push({{i, j + 1}, time + 1});
                check[i][j + 1] = true;
            }
        }
    }

    int orangesRotting(vector<vector<int>>& grid) {
        int ans = 0;
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> check(n, vector<bool>(m, false));
        check_rotting(grid, check, n, m, ans);

        // Check if any fresh orange is left
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && !check[i][j]) return -1;
            }
        }

        return ans;
    }
};

// Driver code for testing
int main() {
    Solution sol;

    vector<vector<int>> grid = {
        {2,1,1},
        {1,1,0},
        {0,1,1}
    };

    int result = sol.orangesRotting(grid);
    cout << "Minimum minutes to rot all oranges: " << result << endl;

    return 0;
}
