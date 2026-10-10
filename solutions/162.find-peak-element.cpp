#include <iostream>
#include <vector>
using namespace std;

class Solution {
    /** 162. Find Peak Element
        https://leetcode.com/problems/find-peak-element
        A peak element is an element that is strictly greater than its neighbors.

        Given a 0-indexed integer array nums, find a peak element, and return its index. If the array contains multiple peaks, return the index to any of the peaks.

        You may imagine that nums[-1] = nums[n] = -∞. In other words, an element is always considered to be strictly greater than a neighbor that is outside the array.

        You must write an algorithm that runs in O(log n) time.
     */
private:
    int findRecurrion(const vector<int>& nums, const size_t& ll, const size_t& rr) {
        if (ll + 2 > rr) return -1;
        const size_t mm = (ll + rr) / 2;
        if (nums[mm] > nums[mm - 1] && nums[mm] > nums[mm + 1]) return mm;
        if (mm + 1 < rr) {
            if (nums[mm + 1] > nums[mm] && nums[mm + 1] > nums[mm + 2]) return mm + 1;
        }
        const int lv = findRecurrion(nums, ll, mm);
        if (0 <= lv) return lv;
        const int rv = findRecurrion(nums, mm + 1, rr);
        if (0 <= rv) return rv;
        return -1;
    }

public:
    int findPeakElement(vector<int>& nums) {
        const size_t nn = nums.size();
        if (1 == nn) return 0;
        if (nums[0] > nums[1]) return 0;
        if (nums[nn - 1] > nums[nn - 2]) return nn - 1;
        return findRecurrion(nums, 0, nn - 1);
    }
};

int main(void)
{
	vector<int> nums = {1,2,3,4,5,4}; // 4
//	vector<int> nums = {1,2,1,3,5,6,4}; // 1 or 5
//	vector<int> nums = {1,2,3,1}; // 2
	
	Solution solution;
	cout << solution.findPeakElement(nums) << endl;
}
