class Solution {
    /** 42. Trapping Rain Water
     * https://leetcode.com/problems/trapping-rain-water/
     */
public:
    int trap(vector<int>& height) {
        const int N = height.size();
        vector<int> presum(N + 1);
        for (int i = 1; i <= N; ++i) presum[i] = presum[i - 1] + height[i - 1];
        // for (auto x: presum) { cout << x << ','; } cout << endl;
        vector<int> next_gt(N, N);
        {
            vector<int> st;
            for (int i = 0; i < N; ++i) {
                while (!st.empty() && height[st.back()] <= height[i]) {
                    next_gt[st.back()] = i;
                    st.pop_back();
                }
                if (!st.empty()) next_gt[st.back()] = i;
                st.push_back(i);
            }
            // for (auto x: next_gt) { cout << x << ','; } cout << endl;
        }
        int res = 0;
        for (int i = 0; i < N;) {
            const int ng = next_gt[i];
            if (N == ng) {
                ++i;
                continue;
            }
            res += min(height[i], height[ng]) * (ng - i - 1) - (presum[ng] - presum[i + 1]);
            // cout << i << "->" << ng << ':' << res << endl;;
            i = ng;
        }
        return res;
    }
};

class Solution {
public:
    int trap(vector<int>& height) {
        const int N = height.size();
        int L = 0, R = N - 1;
        int lmax = 0, rmax = 0;
        int res = 0;
        for (; L <= R;) {
            lmax = max(lmax, height[L]);
            rmax = max(rmax, height[R]);
            if (lmax < rmax) res += lmax - height[L++];
            else res += rmax - height[R--];
            // cout << L << "," << lmax << "<>" << R << ',' << rmax << ':' << res << endl;
        }
        return res;
    }
};