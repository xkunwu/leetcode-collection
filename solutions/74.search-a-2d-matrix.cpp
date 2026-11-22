class Solution {
    /** 74. Search a 2D Matrix
     * https://leetcode.com/problems/search-a-2d-matrix/
     */
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        const int m = matrix.size();
        const int n = matrix[0].size();
        int rl = 0, rr = m - 1;
        while (rl < rr) {
            const int rm = rl + (rr - rl) / 2;
            if (matrix[rm][0] == target) return true;
            else if (matrix[rm][0] > target) rr = rm - 1;
            else if (matrix[rm + 1][0] > target) {
                rl = rm;
                break;
            } else rl = rm + 1;
        }
        // cout << rl << ':';
        // int cl = 1, cr = n - 1; // The second binary search starts at index 1 instead of 0, skipping the first element of the row.
        int cl = 0, cr = n - 1;
        while (cl <= cr) {
            const int cm = cl + (cr - cl) / 2;
            if (matrix[rl][cm] == target) return true;
            else if (matrix[rl][cm] > target) cr = cm - 1;
            else cl = cm + 1;
            // cout << cm << ',';
        }
        return false;
    }
};