#include <iostream>
#include <vector>
using namespace std;

class Solution {
    /** 1732. Find the Highest Altitude
     * https://leetcode.com/problems/find-the-highest-altitude/
     */
public:
    int largestAltitude(vector<int>& gain) {
        int maxAlt = gain[0];
        for (size_t i = 1; i < gain.size(); ++i) {
            gain[i] += gain[i - 1];
            if (gain[i] > maxAlt) maxAlt = gain[i];
        }
        return (maxAlt < 0) ? 0 : maxAlt;
    }
};

int main(void)
{
    vector<int> gain = {52,-91,72}; // 52: 52 -39 33
    // vector<int> gain = {-4,-3,-2,-1,4,3,2}; // 0: [0,-4,-7,-9,-10,-6,-3,-1]
    // vector<int> gain = {-5,1,5,0,-7}; // 1: [0,-5,-4,1,1,-6]

    Solution solution;
    cout << solution.largestAltitude(gain) << endl;
    for (const int& n: gain) cout << n << ' ';
    cout << endl;
}