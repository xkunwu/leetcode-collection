/** 560. Subarray Sum Equals K
	https://leetcode.com/problems/subarray-sum-equals-k/
	Given an array of integers and an integer k, you need to find the total number of continuous subarrays whose sum equals to k.
*/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        std::map<int, int> cumap;
        int sum = 0, nc = 0;
        cumap.insert(pair<int, int>(0, 1));
        for (size_t ii = 0; ii < nums.size(); ++ii) {
            sum += nums[ii];
            const int comp = sum - k;
            if (cumap.end() != cumap.find(comp)) {
                nc += cumap[comp];
            }
            if (cumap.end() == cumap.find(sum))
                cumap.insert(std::pair<int, int>(sum, 1));
            else cumap[sum] += 1;
        }
        return nc;
    }
};

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int nc = 0;
        const size_t nn = nums.size();
        std::vector<int> cumsum(nn + 1, 0);
        for (size_t ii = 1; ii <= nn; ++ ii) {
            cumsum[ii] = cumsum[ii - 1] + nums[ii - 1];
        }
        for (size_t ii = 0; ii < nn; ++ii) {
            for (size_t jj = ii + 1; jj <= nn; ++jj) {
                if (cumsum[jj] - cumsum[ii] == k)
                    ++nc;
            }
        }
        return nc;
    }
};
