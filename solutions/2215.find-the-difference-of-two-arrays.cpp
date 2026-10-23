#include <iostream>
#include <vector>
#include <set>
using namespace std;

class SolutionSet {
    /** 2215. Find the Difference of Two Arrays
     * https://leetcode.com/problems/find-the-difference-of-two-arrays/
     */
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        set s1(nums1.begin(), nums1.end()), s2(nums2.begin(), nums2.end());
        // for (const int& n: s1) { cout << n << ' '; } cout << endl;
        // for (const int& n: s2) { cout << n << ' '; } cout << endl;
        vector<vector<int>> res(2);
        for (const int& n1: s1) {
            if (s2.end() == s2.find(n1)) {
                res[0].push_back(n1);
            }
        }
        // for (const int& n: res[0]) { cout << n << ' '; } cout << endl;
        for (const int& n2: s2) {
            if (s1.end() == s1.find(n2)) {
                res[1].push_back(n2);
            }
        }
        // for (const int& n: res[1]) { cout << n << ' '; } cout << endl;
        return res;
    }
};

class Solution {
    /** 2215. Find the Difference of Two Arrays
     * https://leetcode.com/problems/find-the-difference-of-two-arrays/
     */
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        nums1.erase(unique(nums1.begin(), nums1.end()), nums1.end());
        nums2.erase(unique(nums2.begin(), nums2.end()), nums2.end());
        vector<vector<int>> res(2);
        set_difference(
            nums1.begin(), nums1.end(),
            nums2.begin(), nums2.end(),
            back_inserter(res[0])
        );
        set_difference(
            nums2.begin(), nums2.end(),
            nums1.begin(), nums1.end(),
            back_inserter(res[1])
        );
        return res;
    }
};

int main(void)
{
    // vector<int> nums1 = {1,2,3,3}, nums2 = {1,1,2,2}; // [[3],[]]
    vector<int> nums1 = {1,2,3}, nums2 = {2,4,6}; // [[1,3],[4,6]]

    Solution solution;
    vector<vector<int>> res = solution.findDifference(nums1, nums2);
    for (const int& n: res[0]) { cout << n << ' '; } cout << endl;
    for (const int& n: res[1]) { cout << n << ' '; } cout << endl;
    cout << endl;
}