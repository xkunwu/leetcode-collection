class Solution {
    /** 452. Minimum Number of Arrows to Burst Balloons
     * https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/
     */
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) { return a[0] < b[0]; });
        int res = 1;
        int e = points[0][1];
        for (size_t i = 1; i < points.size(); ++i) {
            const auto& p = points[i];
            // cout << e << "<>" << p[0] << ',' << p[1] << ':';
            if (e < p[0]) {
                ++res;
                e = p[1];
            } else if (p[1] < e) {
                e = p[1];
            }
            // cout << e << endl;
        }
        return res;
    }
};

class Solution {
    /** 452. Minimum Number of Arrows to Burst Balloons
     * https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/
     */
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) { return a[1] < b[1]; });
        size_t overlap = 0;
        int e = points[0][1];
        for (size_t i = 1; i < points.size(); ++i) {
            const auto& p = points[i];
            if (p[0] > e) {
                e = p[1];
            } else {
                ++overlap;
            }
        }
        return points.size() - overlap;
    }
};

class Solution {
    /** 452. Minimum Number of Arrows to Burst Balloons
     * https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/
     */
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) { return a[1] < b[1]; });
        int res = 1;
        int e = points[0][1];
        for (size_t i = 1; i < points.size(); ++i) {
            if (points[i][0] > e) {
                ++res;
                e = points[i][1];
            }
        }
        return res;
    }
};