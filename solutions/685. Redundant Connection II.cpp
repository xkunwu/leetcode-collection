/** 685. Redundant Connection II
	https://leetcode.com/problems/redundant-connection-ii/
	In this problem, a rooted tree is a directed graph such that, there is exactly one node (the root) for which all other nodes are descendants of this node, plus every node has exactly one parent, except for the root node which has no parents.

	The given input is a directed graph that started as a rooted tree with N nodes (with distinct values 1, 2, ..., N), with one additional directed edge added. The added edge has two different vertices chosen from 1 to N, and was not an edge that already existed.

	The resulting graph is given as a 2D-array of edges. Each element of edges is a pair [u, v] that represents a directed edge connecting nodes u and v, where u is a parent of child v.

	Return an edge that can be removed so that the resulting graph is a rooted tree of N nodes. If there are multiple answers, return the answer that occurs last in the given 2D-array.
*/

class Solution {
    /** Markovian chain: matrix power, two cases:
        1. 2-to-1: remove redundant but keep connection.
        2. loop: entry on diagonal -> delete the lower-right.
    **/
public:
    deque<vector<int>> sparseMulti(const deque<vector<int>>& a, const deque<vector<int>>& b) {
        deque<vector<int>> res;
        for (const vector<int>& ai : a) {
            for (const vector<int>& bi : b) {
                if (ai[1] == bi[0])
                    res.push_back(vector<int>({ai[0], bi[1]}));
            }
        }
        return res;
    }
    int checkDiagonal(const deque<vector<int>>& a, std::set<int>& inLoop) {
        //int mxe = -1;
        //for (; ai != a.end(); ++ai) {
            //if (mxe < aie[0]) mxe = aie[0];
        //}
        //return mxe;
        inLoop.clear();
        for (const vector<int>& e : a) {
            if (e[0] != e[1]) continue;
            inLoop.insert(e[0]);
        }
        return inLoop.empty() ? -1 : 1;
    }
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        // Case 1
        std::map<int, int> multim;
        int multar = -1, mulh0, mulh1;
        for (vector<int> e : edges) {
            if (multim.count(e[1]) == 1) {
                multar = e[1];
                mulh0 = multim[e[1]];
                mulh1 = e[0]; // this comes later
            }
            else multim[e[1]] = e[0];
        }
        if (0 < multar) {
            // two node pointing to each other
            if (multim[mulh0] == multar) return vector<int>({mulh0, multar});
            else if (multim[mulh1] == multar) return vector<int>({mulh1, multar});
            // root parent must be connected
            if (0 == multim[mulh1]) {
                vector<vector<int>>::reverse_iterator it = edges.rbegin();
                for (; it != edges.rend(); ++it) {
                    if (it->at(0) == mulh1 && it->at(1) != multar)
                        return vector<int>({mulh1, multar});
                }
                return vector<int>({mulh0, multar});
            } else
            return vector<int>({mulh1, multar});
        }
        multim.clear();
        // Case 2
        deque<vector<int>> a0(edges.begin(), edges.end());
        deque<vector<int>> aa(a0);
        std::set<int> inLoop;
        do {
            int found = checkDiagonal(aa, inLoop);
            //if (0 < mxe) break;
            if (0 < found) break;
            aa = sparseMulti(aa, a0);
        } while (true);
        //for (vector<int> e : edges) {
            //if (e[0] == mxe) return e;
        //}
        vector<vector<int>>::reverse_iterator it = edges.rbegin();
        for (; it != edges.rend(); ++it) {
            if (0 < inLoop.count(it->at(0)) && 0 < inLoop.count(it->at(1))) break;
        }
        if (it != edges.rend()) return *it;
        else return vector<int>({-1, inLoop.size()}); // should not be here
    }
};
