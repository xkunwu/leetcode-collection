class Solution {
    /** 73. Set Matrix Zeroes
     * https://leetcode.com/problems/set-matrix-zeroes/
     */
public:
    void setZeroes(vector<vector<int>>& matrix) {
        const int m = matrix.size(), n = matrix[0].size();
        int rf = 0, cf = 0;
        for (int r = 0; r < m; ++r) {
            if (0 == matrix[r][0]) {
                cf = 1; break;
            }
        }
        for (int c = 0; c < n; ++c) {
            if (0 == matrix[0][c]) {
                rf = 1; break;
            }
        }
        for (int r = 1; r < m; ++r) {
            for (int c = 1; c < n; ++c) {
                if (0 == matrix[r][c]) {
                    matrix[0][c] = 0;
                    matrix[r][0] = 0;
                }
            }
        }
        for (int r = 1; r < m; ++r) {
            for (int c = 1; c < n; ++c) {
                if (0 == matrix[0][c] || 0 == matrix[r][0]) {
                    matrix[r][c] = 0;
                }
            }
        }
        if (rf) for (int c = 0; c < n; ++c) matrix[0][c] = 0;
        if (cf) for (int r = 0; r < m; ++r) matrix[r][0] = 0;
    }
};