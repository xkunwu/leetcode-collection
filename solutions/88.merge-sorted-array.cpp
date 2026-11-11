class Solution {
    /** 88. Merge Sorted Array
     * https://leetcode.com/problems/merge-sorted-array/
     */
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = 0, j = 0;
        vector<int> A;
        A.reserve(m + n);
        for (; i < m && j < n;) {
            if (nums1[i] > nums2[j]) A.push_back(nums2[j++]);
            else A.push_back(nums1[i++]);
        }
        while (i < m) A.push_back(nums1[i++]);
        while (j < n) A.push_back(nums2[j++]);
        nums1 = move(A);
    }
};

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int k = m + n - 1;
        --m; --n;
        while (0 <= m && 0 <= n) {
            if (nums1[m] > nums2[n]) nums1[k--] = nums1[m--];
            else nums1[k--] = nums2[n--];
        };
        while (0 <= m) nums1[k--] = nums1[m--];
        while (0 <= n) nums1[k--] = nums2[n--];
    }
};