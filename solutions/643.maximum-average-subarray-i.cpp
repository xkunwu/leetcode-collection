#include <iostream>
#include <vector>
using namespace std;

class Solution {
    /** 643. Maximum Average Subarray I
     * https://leetcode.com/problems/maximum-average-subarray-i/
     */
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int avg = 0;
        for (size_t j = 0; j < k; ++j) {
            avg += nums[j];
        }
        int maxAvg = avg;
        for (size_t j = k; j < nums.size(); ++j) {
            avg += nums[j]; avg -= nums[j - k];
            if (avg > maxAvg) maxAvg = avg; 
        }
        return (double)maxAvg / k;
    }
};

int main(void)
{
    vector<int> nums = {5}; int k = 1; // 5.00000
    // vector<int> nums = {1,12,-5,-6,50,3}; int k = 4; // 12.75000

    Solution solution;
    cout << solution.findMaxAverage(nums, k) << endl;
}