class Solution {
    /** 399. Evaluate Division
     * https://leetcode.com/problems/evaluate-division/
     */
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        map<vector<string>, double> M;
        map<string, vector<string>> adj;
        int i = 0;
        for (const vector<string>& e: equations) {
            M[{e[0], e[0]}] = 1; M[{e[1], e[1]}] = 1;
            M[e] = values[i++];
            M[{e[1], e[0]}] = 1.f / M[e];
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        // for (auto [k, v]: M) { cout << k[0] << ',' << k[1] << ':' << v << ' '; } cout << endl;
        // for (auto [k, v]: adj) { cout << k << ':'; for (auto vi: v) { cout << vi << ','; } cout << ' '; } cout << endl;
        unordered_set<string> S;
        auto dfs = [&M, &adj, &S](this auto&& self, const string& u, const string& s, const string& e) -> void {
            for (const string& v: adj[u]) {
                if (S.contains(v)) continue;
                S.insert(v);
                M[{s, v}] = M[{s, u}] * M[{u, v}];
                // cout << v << ',';
                if (e == v) return;
                self(v, s, e);
            }
        };
        vector<double> res;
        for (const vector<string>& q: queries) {
            if (!M.contains({q[0], q[0]}) || !M.contains({q[1], q[1]})) {
                res.push_back(-1);
                continue;
            }
            if (M.contains(q)) {
                res.push_back(M[q]);
                continue;
            }
            S.clear();
            S.insert(q[0]);
            dfs(q[0], q[0], q[1]);
            if (M.contains(q)) res.push_back(M[q]);
            else res.push_back(-1);
            // cout << q[0] << ':' << res.size() << endl;
        }
        return res;
    }
};

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        map<string, map<string, double>> M;
        for (size_t i = 0; i < equations.size(); ++i) {
            const vector<string>& e = equations[i];
            M[e[0]][e[1]] = values[i];
            M[e[1]][e[0]] = 1.f / values[i];
            M[e[0]][e[0]] = 1; M[e[1]][e[1]] = 1;
        }
        // for (auto [k, v]: M) { cout << k << ':'; for (auto [k1, v1]: v) { cout << k1 << ',' << v1 << ';'; } cout << ' '; } cout << endl;
        unordered_set<string> S;
        auto dfs = [&M, &S](this auto&& self, const string& u, const string& s, const string& e) -> void {
            S.insert(u);
            for (const auto& [v, w]: M[u]) {
                if (S.contains(v)) continue;
                if (!M[s].contains(v)) M[s][v] = M[s][u] * w;
                // cout << v << ',';
                if (e == v) return;
                self(v, s, e);
            }
        };
        vector<double> res;
        for (const vector<string>& q: queries) {
            if (!M.contains({q[0]}) || !M.contains({q[1]})) {
                res.push_back(-1);
                continue;
            }
            if (q[0] == q[1]) {
                res.push_back(1);
                continue;
            }
            if (M[q[0]].contains(q[1])) {
                res.push_back(M[q[0]][q[1]]);
            } else {
                S.clear();
                dfs(q[0], q[0], q[1]);
                if (M[q[0]].contains(q[1])) {
                    res.push_back(M[q[0]][q[1]]);
                } else res.push_back(-1);
            }
            // cout << q[0] << ':' << res.size() << endl;
            // for (auto [k, v]: M) { cout << k << ':'; for (auto [k1, v1]: v) { cout << k1 << ',' << v1 << ';'; } cout << ' '; } cout << endl;
        }
        return res;
    }
};