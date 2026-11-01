class Solution {
    /** 1431. Kids With the Greatest Number of Candies
     * https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/
     */
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        const int maxe = *max_element(candies.begin(), candies.end());
        vector<bool> res(candies.size(), false);
        for (size_t i = 0; i < candies.size(); ++i) {
            if (maxe <=  candies[i] + extraCandies) res[i] = true;
        }
        return res;
    }
};