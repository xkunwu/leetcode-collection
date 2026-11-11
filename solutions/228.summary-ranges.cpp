class Solution {
    /** 228. Summary Ranges
     * https://leetcode.com/problems/summary-ranges/
     */
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if (0 == nums.size()) return vector<string>();
        if (1 == nums.size()) return vector<string>({format("{}", nums[0])});
        vector<string> res;
        res.reserve(20);
        size_t a = 0, j = 1;
        nums.push_back(nums.back());
        for (; j < nums.size(); ++j) {
            if ((long long)nums[j] - nums[j - 1] == 1) continue;
            if (a == j - 1) res.push_back(format("{}", nums[a]));
            else res.push_back(format("{}->{}", nums[a], nums[j - 1]));
            a = j;
        }
        return move(res);
    }
};

class Solution {
    /** 228. Summary Ranges
     * https://leetcode.com/problems/summary-ranges/
     */
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if (0 == nums.size()) return vector<string>();
        if (1 == nums.size()) return vector<string>({to_string(nums[0])});
        vector<string> res;
        size_t a = 0, j = 1;
        nums.push_back(nums.back());
        for (; j < nums.size(); ++j) {
            if ((long long)nums[j] - nums[j - 1] == 1) continue;
            if (a == j - 1) res.push_back(to_string(nums[a]));
            else res.push_back(to_string(nums[a]) + "->" + to_string(nums[j - 1]));
            a = j;
        }
        return move(res);
    }
};

// [-2147483648,0,2,3,4,6,8,9]; // ["-2147483648","0","2->4","6","8->9"]
// [-2147483648,-2147483647,2147483647]; // ["-2147483648->-2147483647","2147483647"]