class Solution {
	/** 64. Minimum Path Sum
	 * https://leetcode.com/problems/minimum-path-sum/
	 */
public:
    int minPathSum(vector<vector<int>>& grid) {
        const int m = grid.size();
        const int n = grid[0].size();
        for (int c = 1; c < n; ++c) {
            grid[0][c] += grid[0][c - 1];
            // cout << grid[0][c - 1] << ' ';
        }
        // cout << grid[0][n - 1] << endl;
        for (int r = 1; r < m; ++r) {
            grid[r][0] += grid[r - 1][0];
            for (int c = 1; c < n; ++c) {
                grid[r][c] += min(grid[r - 1][c], grid[r][c - 1]);
                // cout << grid[r][c - 1] << ' ';
            }
            // cout << grid[r][n - 1] << endl;
        }
        return grid[m - 1][n - 1];
    }
};