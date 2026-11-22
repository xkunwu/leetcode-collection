class Solution {
    /** 56. Merge Intervals
     * https://leetcode.com/problems/merge-intervals/
     */
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        const int N = intervals.size();
        vector<vector<int>> res;
        res.reserve(N);
        sort(intervals.begin(), intervals.end());
        int s = intervals[0][0], e = intervals[0][1];
        for (int i = 1; i < N; ++i) {
            if (intervals[i][0] > e) {
                res.push_back({s, e});
                s = intervals[i][0]; e = intervals[i][1];
            } else {
                if (e < intervals[i][1]) e = intervals[i][1];
            }
        }
        res.push_back({s, e});
        return res;
    }
};

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        const int N = intervals.size();
        vector<vector<int>> res;
        res.reserve(N);
        sort(intervals.begin(), intervals.end());
        // for (const auto& i: intervals) { cout << i[0] << ',' << i[1] << ' '; } cout << endl;
        res.push_back(intervals[0]);
        for (int i = 1; i < N; ++i) {
            int& s = res.back()[0]; int& e = res.back()[1];
            if (intervals[i][0] > e) {
                res.push_back(intervals[i]);
            } else {
                if (e < intervals[i][1]) e = intervals[i][1];
            }
        }
        return res;
    }
};