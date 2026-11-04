class Solution {
    /** 2352. Equal Row and Column Pairs
     * https://leetcode.com/problems/equal-row-and-column-pairs/
     */
public:
    int equalPairs(vector<vector<int>>& grid) {
        const size_t N = grid.size();
        map<vector<int>, int> m;
        for (size_t r = 0; r < N; ++r) {
            ++m[grid[r]];
        }
        int res = 0;
        vector<int> cols(N);
        for (size_t c = 0; c < N; ++c) {
            for (size_t r = 0; r < N; ++r) {
                cols[r] = grid[r][c];
            }
            if (m.contains(cols)) res += m[cols];
        }
        return res;
    }
};