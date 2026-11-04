class SolutionGrid {
	/** 994. Rotting Oranges
	 * https://leetcode.com/problems/rotting-oranges/
	 */
public:
	int orangesRotting(vector<vector<int>>& grid) {
		const int di[] = {-1, 0, 1, 0};
		const int dj[] = {0, -1, 0, 1};
		int res = 0, changed = 1;
		const int m = grid.size();
		const int n = grid[0].size();
		while (changed) {
			changed = 0;
			vector<vector<int>> gridOld(grid);
			for (int i = 0; i < m; ++i) {
				for (int j = 0; j < n; ++j) {
					if (2 != gridOld[i][j]) continue;
					for (int k = 0; k < 4; ++k) {
						int ni = i + di[k];
						if (0 > ni || m <= ni) continue;
						int nj = j + dj[k];
						if (0 > nj || n <= nj) continue;
						if (1 == gridOld[ni][nj]) {
							grid[ni][nj] = 2;
							changed = 1;
						}
					}
				}
			}
			// cout << '[';
			// for (int i = 0; i < m; ++i) {
			//     cout << '[';
			//     for (int j = 0; j < n; ++j) {
			//         cout << grid[i][j] << ',';
			//     }
			//     cout << ']';
			// }
			// cout << ']' << endl;
			if (changed) ++res;
		}
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (1 == grid[i][j]) return -1;
			}
		}
		return res;
	}
};

class SolutionVector {
	/** 994. Rotting Oranges
	 * https://leetcode.com/problems/rotting-oranges/
	 */
public:
	int orangesRotting(vector<vector<int>>& grid) {
		deque<vector<int>> q;
		const vector<vector<int>> dij = {
			{-1, 0}, {0, -1}, {1, 0}, {0, 1}
		};
		int fresh = 0;
		const int m = grid.size();
		const int n = grid[0].size();
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (1 == grid[i][j]) ++fresh;
				else if (2 == grid[i][j]) {
					q.push_back({i, j});
				}
			}
		}
		int l = 0, r = q.size();
		int rear = r;
		int step = 0;
        int fresh0 = fresh;
		while (l < rear) {
			for (int k = 0; k < 4; ++k) {
				vector<int> nij = {q[l][0] + dij[k][0], q[l][1] + dij[k][1]};
				if (0 > nij[0] || m <= nij[0] || 0 > nij[1] || n <= nij[1]) continue;
				// if (q.end() != q.find(q.begin(), q.end(), nij)) continue;
				if (1 == grid[nij[0]][nij[1]]) {
					--fresh;
					grid[nij[0]][nij[1]] = 2;
					q.push_back(move(nij));
					++rear;
                    // cout << l << ',' << r << ',' << rear << '@' << step << ": " << fresh << endl;
				}
			}
			if (++l < r) continue;
            if (fresh0 > fresh) ++step;
            fresh0 = fresh;
			// cout << l << ',' << r << ',' << rear << '@' << step << ": " << fresh << ", [";
			// for (int i = 0; i < m; ++i) {
			// 	cout << '[';
			// 	for (int j = 0; j < n; ++j) {
			// 		cout << grid[i][j] << ',';
			// 	}
			// 	cout << ']';
			// }
			// cout << "]" << endl;
            r = rear;
		}
		if (0 < fresh) return -1;
		return step;
	}
};

class SolutionQueue {
	/** 994. Rotting Oranges
	 * https://leetcode.com/problems/rotting-oranges/
	 */
public:
	int orangesRotting(vector<vector<int>>& grid) {
		queue<vector<int>> q;
		const vector<vector<int>> dij = {
			{-1, 0}, {0, -1}, {1, 0}, {0, 1}
		};
		int fresh = 0;
		const int m = grid.size();
		const int n = grid[0].size();
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (1 == grid[i][j]) ++fresh;
				else if (2 == grid[i][j]) {
					q.push({i, j});
				}
			}
		}
		int step = 0;
		while (!q.empty() && 0 < fresh) {
            const size_t len = q.size();
            ++step;
            for (size_t l = 0; l < len; ++l) {
                const vector<int>& qf = q.front();
                for (int k = 0; k < 4; ++k) {
                    vector<int> nij = {qf[0] + dij[k][0], qf[1] + dij[k][1]};
                    if (0 > nij[0] || m <= nij[0] || 0 > nij[1] || n <= nij[1]) continue;
                    if (1 == grid[nij[0]][nij[1]]) {
                        --fresh;
                        grid[nij[0]][nij[1]] = 2;
                        q.push(move(nij));
                    }
                }
                q.pop();
            }
		}
		if (0 < fresh) return -1;
		return step;
	}
};

class Solution {
	/** 994. Rotting Oranges
	 * https://leetcode.com/problems/rotting-oranges/
	 */
public:
	int orangesRotting(vector<vector<int>>& grid) {
		queue<pair<int, int>> q;
		const int dij[4][2] = {
			{-1, 0}, {0, -1}, {1, 0}, {0, 1}
		};
		int fresh = 0;
		const int m = grid.size();
		const int n = grid[0].size();
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (1 == grid[i][j]) ++fresh;
				else if (2 == grid[i][j]) {
					q.emplace(i, j);
				}
			}
		}
		int step = 0;
		while (!q.empty() && 0 < fresh) {
            const size_t len = q.size();
            ++step;
            for (size_t l = 0; l < len; ++l) {
                const auto& [x, y] = q.front();
                for (const auto& d: dij) {
                    int nx = x + d[0], ny = y + d[1];
                    if (0 > nx || m <= nx || 0 > ny || n <= ny) continue;
                    if (1 == grid[nx][ny]) {
                        --fresh;
                        grid[nx][ny] = 2;
                        q.emplace(nx, ny);
                    }
                }
                q.pop();
            }
		}
		if (0 < fresh) return -1;
		return step;
	}
};