class Solution {
    /** 435. Non-overlapping Intervals
     * https://leetcode.com/problems/non-overlapping-intervals/
     */
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        ranges::sort(intervals, [](const vector<int>& a, const vector<int>& b) { return a[1] < b[1]; });
        int res = 0, f = intervals[0][1];
        for (size_t i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] < f) ++res;
            else f = intervals[i][1];
        }
        return res;
    }
};