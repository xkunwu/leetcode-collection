#include<vector>
#include<string>
#include<algorithm>
#include<iostream>
#include<sstream>
using namespace std;


/** Example
 * Input: nums = [-1,0,3,5,9,12], target = 9
 * Output: 4
 * Input: nums = [-1,0,3,5,9,12], target = 2
 * Output: -1
 */
class Solution {
public:
    int search(vector<int>& nums, int target) {
        unsigned right = nums.size() - 1;
        if (0 > right) return -1;
        unsigned left = 0, mid;
        while (left < right) {
            mid = left + (right - left + 1) / 2;
            if (target < nums[mid])
                right = mid - 1;
            else left = mid;
        }
        if (target == nums[left]) return left;
        else return -1;
    }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);
        getline(cin, line);
        int target = stringToInteger(line);
        
        int ret = Solution().search(nums, target);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
