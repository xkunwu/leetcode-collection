/** 983. Minimum Cost For Tickets
	https://leetcode.com/problems/minimum-cost-for-tickets/
	In a country popular for train travel, you have planned some train travelling one year in advance.  The days of the year that you will travel is given as an array days.  Each day is an integer from 1 to 365.

	Train tickets are sold in 3 different ways:

		- a 1-day pass is sold for costs[0] dollars;
		- a 7-day pass is sold for costs[1] dollars;
		- a 30-day pass is sold for costs[2] dollars.
		
	The passes allow that many days of consecutive travel.  For example, if we get a 7-day pass on day 2, then we can travel for 7 days: day 2, 3, 4, 5, 6, 7, and 8.

	Return the minimum number of dollars you need to travel every day in the given list of days.
*/

class Solution {
public:
    int findCost(const int& d, vector<int>& vecTab, std::set<int>& daysSet, const vector<int>& days, const vector<int>& costs) {
        if (365 < d) return 0;
        if (0 < vecTab[d]) return vecTab[d];

        int cost;
        if (0 < daysSet.count(d)) {
            cost = std::min<int>(
                findCost(d + 1, vecTab, daysSet, days, costs) + costs[0],
                findCost(d + 7, vecTab, daysSet, days, costs) + costs[1]
            );
            cost = std::min<int>(
                cost,
                findCost(d + 30, vecTab, daysSet, days, costs) + costs[2]
            );
        } else {
            cost = findCost(d + 1, vecTab, daysSet, days, costs);
        }

        vecTab[d] = cost;
        return cost;
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> vecTab(366, -1);
        std::set<int> daysSet(days.begin(), days.end());
        return findCost(1, vecTab, daysSet, days, costs);
    }
};

class Solution {
    const vector<int> dayspan = {1, 7, 30};
public:
    int findCost(const int& d, vector<int>& vecTab, const vector<int>& days, const vector<int>& costs) {
        //cout << d << " ====\n";
        if (vecTab.size() <= d) return 0;
        if (0 < vecTab[d]) return vecTab[d];

        int cost = numeric_limits<int>::max();
        int d2ds = d + 1;
        for (int si = 0; si < 3; ++si) {
            // NOTE: playground is obviously debug mode, while test is release.
            // So if playground works but test complains heap access error,
            // double check out-of-range index.
            while (d2ds < days.size()) {
                if (days[d2ds] - days[d] < dayspan[si])
                    ++d2ds;
                else break;
            }
            cost = std::min<int>(
                cost,
                findCost(d2ds, vecTab, days, costs) + costs[si]
            );
            //cout << si << ": " << d2ds << " -> " << cost << endl;
        }
        vecTab[d] = cost;
        return cost;
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> vecTab(days.size(), -1);
        return findCost(0, vecTab, days, costs);
    }
};
