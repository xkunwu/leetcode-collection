/** 215. Kth Largest Element in an Array
	https://leetcode.com/problems/kth-largest-element-in-an-array/
	Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.
*/

class Solution {
    /** Using QuickSort Partition.
        Terminate when the target is at the right position.
    **/
    int partition(vector<int> &array, int l, int r) {
        const int pivot = array[l]; // pivot is the left-most
        int ii = r; // all elements to the right are smaller
        for (int jj = r; jj > l; --jj) { // start at the same (right-most) position
            if (pivot > array[jj]) {
                swap(array[ii], array[jj]);
                --ii; // move slower than jj
            }
        }
        // cout << " -> " << l << ", " << ii << ", " << r << ": ";
        // for (int kk = l; kk <= r; ++kk) cout << array[kk] << " "; cout << endl;
        swap(array[l], array[ii]);
        return ii;
    }
    int findQuick(vector<int> &array, int l, int r, int k) {
        // cout << l << ", " << k << ", " << r << ": ";
        // for (int kk : array) cout << kk << " "; cout << endl;
        if (0 > k || r - l < k) return -1;
        int pos = partition(array, l, r);
        int delta = pos - l;
        if (delta == k) return array[pos];
        else if (delta > k) return findQuick(array, l, pos - 1, k);
        else return findQuick(array, pos + 1, r, k - delta - 1);
    }
public:
    int findKthLargest(vector<int>& nums, int k) {
        return findQuick(nums, 0, nums.size() - 1, k - 1);
    }
};

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        --k;
        nth_element(
            nums.begin(), nums.begin() + k, nums.end(),
            greater<int>());
        for (int nn : nums) cout << nn << " "; cout << endl;
        return nums[k];
    }
};
