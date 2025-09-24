#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // DFS to mark connected '1's as visited
    void DFS(int i, int j, vector<vector<char>>& grid, vector<vector<bool>>& visited, int n, int m) {
        if (i < 0 || j < 0 || i >= n || j >= m || visited[i][j] || grid[i][j] != '1')
            return;

        visited[i][j] = true;

        DFS(i - 1, j, grid, visited, n, m); // up
        DFS(i + 1, j, grid, visited, n, m); // down
        DFS(i, j - 1, grid, visited, n, m); // left
        DFS(i, j + 1, grid, visited, n, m); // right
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();        // rows
        int m = grid[0].size();     // cols
        int islands = 0;

        vector<vector<bool>> visited(n, vector<bool>(m, false));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1' && !visited[i][j]) {
                    DFS(i, j, grid, visited, n, m);
                    islands++;
                }
            }
        }
        return islands;
    }
};

int main() {
    Solution sol;

    // Example test grid
    vector<vector<char>> grid = {
        {'1', '1', '0', '0'},
        {'1', '0', '0', '1'},
        {'0', '0', '1', '1'}
    };

    int result = sol.numIslands(grid);
    cout << "Number of islands: " << result << endl;

    return 0;
}
