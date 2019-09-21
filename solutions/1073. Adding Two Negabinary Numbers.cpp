/** 1073. Adding Two Negabinary Numbers
	https://leetcode.com/problems/adding-two-negabinary-numbers/
	Given two numbers arr1 and arr2 in base -2, return the result of adding them together.

	Each number is given in array format:  as an array of 0s and 1s, from most significant bit to least significant bit.  For example, arr = [1,1,0,1] represents the number (-2)^3 + (-2)^2 + (-2)^0 = -3.  A number arr in array format is also guaranteed to have no leading zeros: either arr == [0] or arr[0] == 1.

	Return the result of adding arr1 and arr2 in the same format: as an array of 0s and 1s with no leading zeros.
*/

class Solution {
    /** Negabinary representation:
        0 = 000
        1 = 001
        2 = 110
        3 = 111
        4 = 100
        Adding rule:
        000 + 1 -> 001, 000 + 2 -> 110
        011 + 1 -> 000, 011 + 2 -> 001
        001 + 1 -> 110, 001 + 2 -> 111
        or:
        0 + 0 -> 000, 0 + 1 -> 001, 0 + 2 -> 110, 0 + 3 -> 111
        1 + 0 -> 010, 1 + 1 -> 011, 1 + 2 -> 000, 1 + 3 -> 001
    */
public:
    typedef array<int, 2> vec2;
    vec2 sum_plus(int& sum, const vec2& plus) {
        sum += plus[1];
        if (0 == plus[0]) {
            if (2 > sum) return vec2{0, 0};
            else {
                sum -= 2;
                return vec2{1, 1};
            }
        } else {
            if (2 > sum) return vec2{0, 1};
            else {
                sum -= 2;
                if (0 == sum) return vec2{0, 0};
            }
        }
        return vec2{0, 0}; // should not be here
    }
    vector<int> addNegabinary(vector<int>& arr1, vector<int>& arr2) {
        deque<int> res;
        vector<int>::reverse_iterator i1 = arr1.rbegin();
        vector<int>::reverse_iterator i2 = arr2.rbegin();
        int sum;
        vec2 plus;
        plus.fill(0);
        while (true) {
            if (i1 == arr1.rend() && i2 == arr2.rend()) break;
            if (i1 == arr1.rend()) {
                sum = *i2;
                plus = sum_plus(sum, plus);
                res.push_front(sum);
                ++i2;
            } else if (i2 == arr2.rend()) {
                sum = *i1;
                plus = sum_plus(sum, plus);
                res.push_front(sum);
                ++i1;
            } else {
                sum = *i1 + *i2;
                plus = sum_plus(sum, plus);
                res.push_front(sum);
                ++i1; ++i2;
            }
        }
        if (res.empty()) return vector<int>(1, 0); // both empty
        res.push_front(plus[1]);
        res.push_front(plus[0]);
        deque<int>::iterator rit = res.begin();
        while (*rit == 0) ++rit;
        if (rit == res.end()) return vector<int>(1, 0); // both 0
        return vector<int>(rit, res.end());
    }
};
