class SolutionVector {
    /** 1926. Nearest Exit from Entrance in Maze
     * https://leetcode.com/problems/nearest-exit-from-entrance-in-maze/
     */
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        const vector<int> vd[] = {{-1,0}, {0,1}, {1,0}, {0,-1}};
        const int m = maze.size(), n = maze[0].size();
        vector<vector<int>> cur(1, entrance), nxt;
        maze[entrance[0]][entrance[1]] = '+';
        int res = 0;
        while (!cur.empty()) {
            for (const vector<int>& p: cur) {
                for (const vector<int>& d: vd) {
                    vector<int> pn = {p[0] + d[0], p[1] + d[1]};
                    if (0 > pn[0] || m <= pn[0] || 0 > pn[1] || n <= pn[1]) {
                        if (p == entrance) continue;
                        else return res;
                    }
                    if ('+' == maze[pn[0]][pn[1]]) continue;
                    maze[pn[0]][pn[1]] = '+';
                    nxt.push_back(pn);
                }
            }
            cur = move(nxt);
            ++res;
        }
        return -1;
    }
};

class SolutionPair {
    /** 1926. Nearest Exit from Entrance in Maze
     * https://leetcode.com/problems/nearest-exit-from-entrance-in-maze/
     */
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        const int v0[] = {-1, 0, 1, 0};
        const int v1[] = {0, 1, 0, -1};
        const int m = maze.size(), n = maze[0].size();
        vector<pair<int, int>> cur(1, {entrance[0], entrance[1]}), nxt;
        maze[entrance[0]][entrance[1]] = '+';
        int res = 0;
        while (!cur.empty()) {
            for (const auto& [r, c]: cur) {
                for (int i = 0; i < 4; ++i) {
                    const int nr = r + v0[i], nc = c + v1[i];
                    if (0 > nr || m <= nr || 0 > nc || n <= nc) {
                        if (r == entrance[0] && c == entrance[1]) continue;
                        else return res;
                    }
                    if ('+' == maze[nr][nc]) continue;
                    maze[nr][nc] = '+';
                    nxt.push_back({nr, nc});
                }
            }
            cur = move(nxt);
            ++res;
        }
        return -1;
    }
};