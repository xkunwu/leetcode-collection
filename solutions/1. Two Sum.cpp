/** 1. Two Sum
	https://leetcode.com/problems/two-sum/
	Given an array of integers, return indices of the two numbers such that they add up to a specific target.

	You may assume that each input would have exactly one solution, and you may not use the same element twice.
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::map<int, int> v2i;
        for (int i = 0; i < nums.size(); ++i) {
            int vi_c = target - nums[i];
            if (v2i.end() == v2i.find(vi_c))
                v2i.insert({nums[i], i});
            else
                return vector<int>({v2i[vi_c], i});
        }
        return vector<int>({-1, -1});
    }
};

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        size_t nn = nums.size();
        int i = 0;
        int j = 0;
        for (; i < nn - 1; ++i) {
            for (j = i + 1; j < nn; ++j) {
                if (nums[i] + nums[j] == target) return vector<int>({i, j});
            }
        }
        return vector<int>({-1, -1});
    }
};

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        size_t nn = nums.size();
        size_t i = 0;
        size_t j = 0;
        for (; i < nn - 1; ++i) {
            for (j = i + 1; j < nn; ++j) {
                if (nums[i] + nums[j] == target) break;
            }
            if (j < nn) break;
        }
        return vector<int>({i, j});
    }
};