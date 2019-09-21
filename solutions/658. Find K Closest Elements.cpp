/** 658. Find K Closest Elements
	https://leetcode.com/problems/find-k-closest-elements/
	Given a sorted array, two integers k and x, find the k closest elements to x in the array. The result should also be sorted in ascending order. If there is a tie, the smaller elements are always preferred.
*/

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int>::iterator ai0 = arr.begin();
        vector<int>::iterator ai1 = ai0 + k;
        vector<int>::iterator ai2 = ai1 + 1;
        for (; ai2 != arr.end(); ++ai0, ++ai1) {
            int v0 = abs(*ai0 - x), v1 = abs(*ai1 - x);
            int v2 = abs(*ai2 - x);
            if (v2 > v0) break;
        }
        return vector<int>(ai0, ai1);
    }
};
