#include <iostream>
#include <string>
#include <queue>
#include <vector>
using namespace std;

class SolutionSimu {
	/** 649. Dota2 Senate
	 * https://leetcode.com/problems/dota2-senate/
	 * 
	 * Simulation solves the problem with bad performance - think further to find a better model.
	 */
public:
    string predictPartyVictory(string senate) {
    	const size_t nc = senate.size();
		size_t nr = 0, nd = 0;
		for (const char& c: senate) {
			if ('R' == c) ++nr;
			else ++nd;
		}
    	while ((0 < nr) && (0 < nd)) {
//    		for (const auto& c: senate) cout << c;
//    		cout << endl;
			for (size_t i = 0; i < nc; ++i) {
	        	if ('x' == senate[i]) continue;
	        	const char& c = senate[i];
	        	size_t j;
				if ('R' == c) {
					for (j = i + 1; j < nc; ++j) {
						if ('x' == senate[j]) continue;
						if (c == senate[j]) continue;
						senate[j] = 'x';
						--nd;
						break;
					}
					if (j < nc) continue;
					for (j = 0; j < i; ++j) {
						if ('x' == senate[j]) continue;
						if (c == senate[j]) continue;
						senate[j] = 'x';
						--nd;
						break;
					}
				} else if ('D' == c) {
					for (j = i + 1; j < nc; ++j) {
						if ('x' == senate[j]) continue;
						if (c == senate[j]) continue;
						senate[j] = 'x';
						--nr;
						break;
					}
					if (j < nc) continue;
					for (j = 0; j < i; ++j) {
						if ('x' == senate[j]) continue;
						if (c == senate[j]) continue;
						senate[j] = 'x';
						--nr;
						break;
					}
				}
			}
		}
		if (0 < nd) return "Dire";
		else return "Radiant";
    }
};

class Solution {
	/** 649. Dota2 Senate
	  https://leetcode.com/problems/dota2-senate/
	 */
public:
	string predictPartyVictory(string senate) {
		int Rw, Dw, flag = 0;
		do {
//			for (const auto& c: senate) { cout << c; } cout << endl;
			Dw = Rw = 0;
			for(size_t i = 0; i < senate.size(); ++i){
				const char& c = senate[i];
				if ('R' == c) {
					if (0 > flag) senate[i] = 'x';
					else ++Rw;
					++flag;
				} else if ('D' == c) {
					if (0 < flag) senate[i] = 'x';
					else ++Dw;
					--flag;
				}
			}
		} while (Rw && Dw);
		return (0 < Rw) ? "Radiant" : "Dire";
	}
};

int main(void)
{
	string senate = "DRRDRDRDRDDRDRDR"; // "Radiant"
//	string senate = "RDD"; // "Dire"
//	string senate = "RD"; // "Radiant"

	Solution solution;
	cout << solution.predictPartyVictory(senate) << endl;
}
