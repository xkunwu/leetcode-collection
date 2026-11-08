class Solution {
    /** 2530. Maximal Score After Applying K Operations
     * https://leetcode.com/problems/maximal-score-after-applying-k-operations/
     */
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> q(less<int>(), move(nums));
        long long res = 0;
        while (k--) {
            const int m = q.top();
            res += m;
            q.pop();
            q.push((m - 1) / 3 + 1);
            // cout << m << ' ' << res << endl;
        }
        return res;
    }
};

class Solution {
    /** 2530. Maximal Score After Applying K Operations
     * https://leetcode.com/problems/maximal-score-after-applying-k-operations/
     */
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long res = 0;
        make_heap(nums.begin(), nums.end());
        while (k--) {
            res += nums.front();
            pop_heap(nums.begin(), nums.end());
            nums.back() = (nums.back() - 1) / 3 + 1;
            push_heap(nums.begin(), nums.end());
        }
        return res;
    }
};