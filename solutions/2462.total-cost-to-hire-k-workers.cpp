class Solution {
    /** 2462. Total Cost to Hire K Workers
     * https://leetcode.com/problems/total-cost-to-hire-k-workers/
     */
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        const int N = costs.size();
        long long res = 0;
        if (N == k) {
            for (const int& c: costs) res += c;
            return res;
        }
        int i = candidates, j = N - candidates;
        vector<int> fh;
        vector<int> bh;
        if (j <= i) {
            fh = costs;
        } else {
            fh.assign(costs.begin(), costs.begin() + candidates);
            bh.assign(costs.end() - candidates, costs.end());
        }
        make_heap(fh.begin(), fh.end(), greater<>());
        make_heap(bh.begin(), bh.end(), greater<>());
        // cout << i << ',' << j << ':';
        // cout << fh.size() << '-'; for (int e: fh) { cout << e << ','; } cout << " + ";
        // cout << bh.size() << '-'; for (int e: bh) { cout << e << ','; } cout << endl;
        while (k--) {
            if (i < j) {
                if (bh[0] < fh[0]) {
                    res += bh[0];
                    pop_heap(bh.begin(), bh.end(), greater<>());
                    bh.back() = costs[--j];
                    push_heap(bh.begin(), bh.end(), greater<>());
                } else {
                    res += fh[0];
                    pop_heap(fh.begin(), fh.end(), greater<>());
                    fh.back() = costs[i++];
                    push_heap(fh.begin(), fh.end(), greater<>());
                }
            } else {
                if (i == j && !bh.empty()) {
                    // fh.reserve(candidates + candidates);
                    // move(bh.begin(), bh.end(), back_inserter(fh));
                    fh.insert(fh.end(), bh.begin(), bh.end());
                    make_heap(fh.begin(), fh.end(), greater<>());
                    bh.clear();
                }
                res += fh[0];
                pop_heap(fh.begin(), fh.end(), greater<>());
                fh.pop_back();
                push_heap(fh.begin(), fh.end(), greater<>());
            }
            // cout << res << '@' << k << ',' << i << ',' << j << ':';
            // for (int e: fh) { cout << e << ','; } cout << " + ";
            // for (int e: bh) { cout << e << ','; } cout << endl;
        }
        return res;
    }
};

class Solution {
    /** 2462. Total Cost to Hire K Workers
     * https://leetcode.com/problems/total-cost-to-hire-k-workers/
     */
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        const int N = costs.size();
        if (N < k + 2 * candidates) {
            nth_element(costs.begin(), costs.begin() + k, costs.end());
            return accumulate(costs.begin(), costs.begin() + k, 0LL);
        }
        vector<int> fh(costs.begin(), costs.begin() + candidates);
        vector<int> bh(costs.end() - candidates, costs.end());
        make_heap(fh.begin(), fh.end(), greater<>());
        make_heap(bh.begin(), bh.end(), greater<>());
        long long res = 0;
        int i = candidates, j = N - candidates;
        while (k--) {
            if (bh[0] < fh[0]) {
                res += bh[0];
                pop_heap(bh.begin(), bh.end(), greater<>());
                bh.back() = costs[--j];
                push_heap(bh.begin(), bh.end(), greater<>());
            } else {
                res += fh[0];
                pop_heap(fh.begin(), fh.end(), greater<>());
                fh.back() = costs[i++];
                push_heap(fh.begin(), fh.end(), greater<>());
            }
        }
        return res;
    }
};