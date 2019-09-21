class Solution {
	/** #4. Median of Two Sorted Arrays
		https://leetcode.com/problems/3sum-closest/
		There are two sorted arrays nums1 and nums2 of size m and n respectively.

		Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

		You may assume nums1 and nums2 cannot be both empty.
		
		Comments:
		Median means it partition the array into two sets, such that:
        Largest of one set is smaller than the smallest of the other.
	*/
public:
    double findOrdered(const vector<int> &nums1, const vector<int> &nums2, const int &nn1, const int &nn2) {
        // median should be at here either even/odd total numbers.
        const int msum = (nn1 + nn2 + 1) >> 1;
        int minx = 0, maxx = nn1, part1, part2;
        // cout << nn1 << " " << nn2 << " -> " << msum << endl;
        do {
            part1 = (minx + maxx) >> 1; // binary search first partition
            part2 = msum - part1; // partition second (larger length) array
            // cout << part1 << " " << part2 << ": " << minx << " " << maxx << " -> ";
            if (0 < part1 && nn2 > part2 && nums1[part1 - 1] > nums2[part2])
                // continue on the left of the first partition
                maxx = part1 - 1;
            else if (0 < part2 && nn1 > part1 && nums2[part2 - 1] > nums1[part1])
                // continue on the right of the first partition
                minx = part1 + 1;
            else break;
            // cout << minx << " " << maxx << endl;
        } while (minx <= maxx);
        // cout << minx << " " << maxx << endl;

        int median;
        // median of the first partition: check out-of-range
        if (0 >= part1) median = nums2[part2 - 1];
        else if (0 >= part2) median = nums1[part1 - 1];
        else median = max(nums1[part1 - 1], nums2[part2 - 1]);
        cout << median << endl;
        // odd: simply return the extra of the first partition
        if (1 & (nn1 + nn2)) return (double)median;
        // even: be carefult of full-range
        if (nn1 <= part1) return (median + nums2[part2]) * 0.5;
        if (nn2 <= part2) return (median + nums1[part1]) * 0.5;
        return (median + min(nums1[part1], nums2[part2])) * 0.5;
    }
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        const int nn1 = nums1.size();
        const int nn2 = nums2.size();
        if (nn1 > nn2) return findOrdered(nums2, nums1, nn2, nn1);
        else return findOrdered(nums1, nums2, nn1, nn2);
    }
};