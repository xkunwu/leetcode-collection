#include <iostream>
#include <vector>
using namespace std;

class Solution {
    /** 283. Move Zeroes
     *  https://leetcode.com/problems/move-zeroes/
     */
public:
    void moveZeroes(vector<int>& nums) {
        int temp;
        auto i = nums.begin();
        auto j = i;
        while (i != nums.end() && 0 != *i) {
            ++i; ++j;
        }
        if (nums.end() == j) return;
        while (++j < nums.end()) {
            if (0 != *j) {
                iter_swap(i, j);
                ++i;
            }
        }
    }
};

int main(void)
{
    vector<int> nums = {1}; // 1
    // vector<int> nums = {0}; // 0
    // vector<int> nums = {0,1,0,3,12}; // 1,3,12,0,0

    Solution solution;
    solution.moveZeroes(nums);
    for (const int& n: nums) cout << n << ' ';
    cout << endl;
}