class Solution {
    /** 1466. Reorder Routes to Make All Paths Lead to the City Zero
     * https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero/
     */
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        int res = 0;
        int ii = 0;
        auto dfs = [&](this auto&& self, const int u) -> void {
            if ((n - 1) == ii) return;
            for (int e = ii; e < n - 1; ++e) {
                if (e < ii) continue;
                if (u == connections[e][0]) {
                    ++res;
                    swap(connections[e], connections[ii]);
                    // cout << u << '@' << e << '/' << connections[ii][0] << ',' << connections[ii][1] << ':' << ii << ' ' << res << endl;
                    ++ii;
                    self(connections[ii - 1][1]);
                } else if (u == connections[e][1]) {
                    swap(connections[e], connections[ii]);
                    // cout << u << '@' << e << '/' << connections[ii][0] << ',' << connections[ii][1] << ':' << ii << ' ' << res << endl;
                    ++ii;
                    self(connections[ii - 1][0]);
                }
            }
        };
        dfs(0);
        return res;
    }
};

class Solution {
    /** 1466. Reorder Routes to Make All Paths Lead to the City Zero
     * https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero/
     */
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        int res = 0;
        --n;
        vector<int> flag(n, 0);
        auto dfs = [&](this auto&& self, const int u) -> void {
            for (int e = 0; e < n; ++e) {
                if (flag[e]) continue;
                if (u == connections[e][0]) {
                    flag[e] = 1;
                    ++res;
                    self(connections[e][1]);
                } else if (u == connections[e][1]) {
                    flag[e] = 1;
                    self(connections[e][0]);
                }
            }
        };
        dfs(0);
        return res;
    }
};

class Solution {
    /** 1466. Reorder Routes to Make All Paths Lead to the City Zero
     * https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero/
     */
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        int res = 0;
        vector<vector<int>> adj0(n), adj1(n);
        for (const vector<int>& c: connections) {
            adj0[c[0]].push_back(c[1]);
            adj1[c[1]].push_back(c[0]);
        }
        vector<int> flag(n, 0);
        auto dfs = [&](this auto&& self, const int u) -> void {
            for (const int& v: adj0[u]) {
                if (flag[v]) continue;
                ++res;
                flag[v] = 1;
                self(v);
            }
            for (const int& v: adj1[u]) {
                if (flag[v]) continue;
                flag[v] = 1;
                self(v);
            }
        };
        flag[0] = 1;
        dfs(0);
        return res;
    }
};

class Solution {
    /** 1466. Reorder Routes to Make All Paths Lead to the City Zero
     * https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero/
     */
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        int res = 0;
        vector<vector<int>> adj(n);
        for (const vector<int>& c: connections) {
            adj[c[0]].push_back(c[1]);
            adj[c[1]].push_back(-c[0]);
        }
        vector<int> flag(n, 0);
        auto dfs = [&](this auto&& self, const int& u) -> void {
            for (const int& v: adj[u]) {
                const int va = abs(v);
                if (flag[va]) continue;
                if (0 < v) ++res;
                flag[va] = 1;
                self(va);
            }
        };
        const int u = 0;
        flag[u] = 1;
        dfs(u);
        return res;
    }
};

class Solution {
    /** 1466. Reorder Routes to Make All Paths Lead to the City Zero
     * https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero/
     */
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        int res = 0;
        vector<vector<int>> adj(n);
        for (const vector<int>& c: connections) {
            adj[c[0]].push_back(c[1]);
            adj[c[1]].push_back(-c[0]);
        }
        vector<int> flag(n, 0);
        auto dfs = [&](this auto&& self, const int& u) -> void {
            flag[u] = 1;
            for (const int& v: adj[u]) {
                if (0 < v && !flag[v]) {
                    ++res;
                    self(v);
                } else if (0 > v && !flag[-v]) {
                    self(-v);
                }
            }
        };
        const int u = 0;
        dfs(u);
        return res;
    }
};