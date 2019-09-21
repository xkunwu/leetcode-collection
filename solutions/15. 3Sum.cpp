/** 15. 3Sum
	https://leetcode.com/problems/3sum/
	Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

	Note:

	The solution set must not contain duplicate triplets.
*/

class Solution {
    struct VecHash {
        size_t operator()(const vector<int> &vec) const {
            ostringstream oss;
            for (int v : vec) oss << v;
            // for (int v : vec) cout << v << " "; cout << " -> "; cout << oss.str(); cout << endl;
            return hash<string>()(oss.str());
        }
    };
    struct VecEqual {
        bool operator()(const vector<int> &vec0, const vector<int> &vec1) const {
            return (vec0[0] == vec1[0]) && (vec0[1] == vec1[1]) && (vec0[2] == vec1[2]);
        }
    };
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if (3 > nums.size()) return vector<vector<int>>();
        sort(nums.begin(), nums.end());
        // vector<vector<int>> ret;
        unordered_set<vector<int>, VecHash, VecEqual> ret;
        for (size_t ii = 0; ii < nums.size() - 2; ++ii) {
            unordered_set<int> seenSet;
            const int curr_sum = - nums[ii];
            for (size_t jj = ii + 1; jj < nums.size(); ++jj) {
                const int curr_sum_jj = curr_sum - nums[jj];
                if (0 < seenSet.count(curr_sum_jj)) {
                    // ret.push_back(vector<int>{nums[ii], curr_sum_jj, nums[jj]});
                    ret.insert(vector<int>{nums[ii], curr_sum_jj, nums[jj]});
                }
                seenSet.insert(nums[jj]);
            }
        }
        return vector<vector<int>>(ret.begin(), ret.end());
    }
};

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ret;
        vector<vector<int>>::iterator lastI = ret.end();
        for (size_t ii = 0; ii < nums.size() - 2; ++ii) {
            unordered_set<int> seenSet;
            const int curr_sum = - nums[ii];
            for (size_t jj = ii + 1; jj < nums.size(); ++jj) {
                const int curr_sum_jj = curr_sum - nums[jj];
                if (0 < seenSet.count(curr_sum_jj)) {
                    ret.push_back(vector<int>{nums[ii], curr_sum_jj, nums[jj]});
                }
                seenSet.insert(nums[jj]);
            }
        }
        return ret;
    }
};
