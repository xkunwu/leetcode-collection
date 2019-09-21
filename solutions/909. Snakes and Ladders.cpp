/** 909. Snakes and Ladders
	https://leetcode.com/problems/snakes-and-ladders/
	On an N x N board, the numbers from 1 to N*N are written boustrophedonically starting from the bottom left of the board, and alternating direction each row.  For example, for a 6 x 6 board, the numbers are written as follows:


	You start on square 1 of the board (which is always in the last row and first column).  Each move, starting from square x, consists of the following:

		- You choose a destination square S with number x+1, x+2, x+3, x+4, x+5, or x+6, provided this number is <= N*N.
			- (This choice simulates the result of a standard 6-sided die roll: ie., there are always at most 6 destinations, regardless of the size of the board.)
		- If S has a snake or ladder, you move to the destination of that snake or ladder.  Otherwise, you move to S.
		
	A board square on row r and column c has a "snake or ladder" if board[r][c] != -1.  The destination of that snake or ladder is board[r][c].

	Note that you only take a snake or ladder at most once per move: if the destination to a snake or ladder is the start of another snake or ladder, you do not continue moving.  (For example, if the board is `[[4,-1],[-1,3]]`, and on the first move your destination square is `2`, then you finish your first move at `3`, because you do not continue moving to `4`.)

	Return the least number of moves required to reach square N*N.  If it is not possible, return -1.
*/

class Solution {
public:
    vector<int> flattenBoard(const vector<vector<int>>& board) {
        vector<int> flatB;
        for (vector<int> vec : board) {
            flatB.insert(flatB.end(), vec.begin(), vec.end());
        }
        for (size_t ii = 0; ii < flatB.size(); ++ii) flatB[ii] -= 1;
        return flatB;
    }
    int getBid(const int& ii, const int& sl) {
        int div = ii / sl;
        int mod = ii % sl;
        int row = sl - div - 1;
        int col = (row % 2 != sl % 2) ? mod : (sl - mod - 1);
        return row * sl + col;
    }
    int snakesAndLadders(vector<vector<int>>& board) {
        vector<int> flatB = flattenBoard(board);
        const int sl = board.size();
        const int bN = flatB.size();
        const int bN_1 = bN - 1;
        queue<int> bfs;
        bfs.push(0);
        map<int, int> dist;
        dist[0] = 0;
        while (!bfs.empty()) {
            const int cp = bfs.front();
            bfs.pop();
            if (cp == bN_1) return dist[cp];
            for (int mt = cp + 1; mt <= cp + 6; ++mt) {
                int mt_d = dist[cp] + 1;
                if (mt >= bN_1) return mt_d;
                int mt_bid = getBid(mt, sl);
                int mt_lad = (0 > flatB[mt_bid]) ? mt : flatB[mt_bid];
                if (mt_lad >= bN_1) return mt_d;
                if (dist.count(mt_lad) == 0) {
                    dist[mt_lad] = mt_d;
                    bfs.push(mt_lad);
                }
            }
        }
        return -1;
    }
};
