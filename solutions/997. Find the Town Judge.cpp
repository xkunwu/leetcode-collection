/** 997. Find the Town Judge
	https://leetcode.com/problems/find-the-town-judge/
	In a town, there are N people labelled from 1 to N.  There is a rumor that one of these people is secretly the town judge.

	If the town judge exists, then:

		1. The town judge trusts nobody.
		2. Everybody (except for the town judge) trusts the town judge.
		3. There is exactly one person that satisfies properties 1 and 2.
		
	You are given trust, an array of pairs trust[i] = [a, b] representing that the person labelled a trusts the person labelled b.

	If the town judge exists and can be identified, return the label of the town judge.  Otherwise, return -1.
*/

class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        vector<int> isS(N + 1, -1);
        map<int, set<int>> tms;
        for (const vector<int> t : trust) {
            isS[t[0]] = 1;
            if (0 == tms.count(t[1]))
                tms[t[1]] = set<int>({t[0]});
            else tms[t[1]].insert(t[0]);
        }
        for (int ni = 1; ni <= N; ++ni) {
            //cout << isS[ni] << " " << tms[ni].size() << endl;
            if (0 < isS[ni]) continue;
            if (N - 1 == tms[ni].size()) return ni;
        }
        return -1;
    }
};
