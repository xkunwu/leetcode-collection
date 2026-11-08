class Solution {
    /** 547. Number of Provinces
     * https://leetcode.com/problems/number-of-provinces/
     */
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        const size_t n = isConnected.size();
        auto dfs = [&isConnected, &n](this auto&& self, const size_t& u) ->void {
            for (size_t v = 0; v < n; ++v) {
                if (u == v) continue;
                if (-1 == isConnected[v][v]) continue;
                if (1 != isConnected[u][v]) continue;
                // cout << v << ',';
                isConnected[v][v] = -1;
                self(v);
            }
        };
        int res = 0;
        for (size_t u = 0; u < n; ++u) {
            if (-1 == isConnected[u][u]) continue;
            isConnected[u][u] = -1;
            dfs(u);
            ++res;
            // cout << u << ':' << res << endl;
        }
        return res;
    }
};