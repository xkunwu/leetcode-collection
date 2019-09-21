class Solution {
	/** #496. Next Greater Element I
		https://leetcode.com/problems/next-greater-element-i/
		You are given two arrays (without duplicates) nums1 and nums2 where nums1’s elements are subset of nums2. Find all the next greater numbers for nums1's elements in the corresponding places of nums2.

		The Next Greater Number of a number x in nums1 is the first greater number to its right in nums2. If it does not exist, output -1 for this number.
	*/
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        const int nn1 = nums1.size();
        const int nn2 = nums2.size();
        for (int n1 = 0; n1 < nn1; ++n1) {
            int n2 = 0;
            while (nums1[n1] != nums2[n2]) ++n2;
            while (n2 < nn2 && nums1[n1] >= nums2[n2]) {
                ++n2;
            }
            if (nn2 > n2) nums1[n1] = nums2[n2];
            else nums1[n1] = -1;
        }
        return nums1;
    }
};

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.empty()) return {};
        int maxE = -1;
        for (int v2 : nums2) if (maxE < v2) maxE = v2;
        vector<int> ansTab(maxE + 1, -1);
        deque<int> revStack;
        revStack.push_back(0);
        for (int n2 = 1; n2 < nums2.size(); ++n2) {
            while (!revStack.empty() && nums2[revStack.back()] < nums2[n2]) {
                ansTab[nums2[revStack.back()]] = nums2[n2];
                revStack.pop_back();
            }
            revStack.push_back(n2);
            // for (deque<int>::iterator it = revStack.begin(); it != revStack.end(); ++it) cout << *it << " "; cout << endl;
        }
        vector<int> ret;
        for (int v1 : nums1) {
            ret.push_back(ansTab[v1]);
        }
        return ret;
    }
};