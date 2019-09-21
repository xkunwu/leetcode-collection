/** 869. Reordered Power of 2
	https://leetcode.com/problems/reordered-power-of-2/
	Starting with a positive integer N, we reorder the digits in any order (including the original order) such that the leading digit is not zero.

	Return true if and only if we can do this in a way such that the resulting number is a power of 2.
*/

class Solution {
public:
    int getNumBits(int N, deque<int>& digN) {
        int nn = 0;
        for (; 1 <= N;) {
            digN.push_back(N % 10);
            ++nn;
            N /= 10;
        };
        return nn;
    }
    int genNewN(const deque<int>& digN, const int& nn) {
        if (digN[nn - 1] == 0) return -1;
        int newN = 0, kx = 1;
        for (int ki = 0; ki < nn; ++ki, kx *= 10) {
            newN += kx * digN[ki];
            cout<<"("<<digN[ki]<<", "<<newN<<") ";
        }
        cout<<endl;
        return newN;
    }
    bool checkN(const int& newN) {
        int p2 = 1;
        while (newN > p2) p2 *= 2;
        return newN == p2;
    }
    bool reorderedPowerOf2(int N) {
        if (checkN(N)) return true;
        deque<int> digN;
        int nn = getNumBits(N, digN);
        for (int d : digN) cout<<d<<" ";
        cout<<endl;
        std::set<int> setN;
        setN.insert(N);
        std::sort(digN.begin(), digN.end());
        do {
            int newN = genNewN(digN, nn);
            if (0 > newN) continue;
            if (0 < setN.count(newN)) continue;
            if (checkN(newN)) return true;
            setN.insert(newN);
            cout<<setN.size()<<endl;
        } while (std::next_permutation(digN.begin(), digN.end()));
        return false;
    }
};
