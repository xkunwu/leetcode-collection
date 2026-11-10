class Solution {
    /** 739. Daily Temperatures
     * https://leetcode.com/problems/daily-temperatures/
     */
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> Sv;
        vector<int> Si;
        int ii = 0;
        for (const int& t: temperatures) {
            if (!Sv.empty() && t > Sv.top()) {
                int j = 0;
                do {
                    ++j;
                    temperatures[Si.back()] += j;
                    Sv.pop(); Si.pop_back();
                } while (!Sv.empty() && t > Sv.top());
                for (const int c: Si) temperatures[c] += j;
            }
            Sv.push(t); Si.push_back(ii);
            temperatures[ii] = 0;
            ++ii;
        }
        for (int& c: Si) temperatures[c] = 0;
        return temperatures;
    }
};

class Solution {
    /** 739. Daily Temperatures
     * https://leetcode.com/problems/daily-temperatures/
     */
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> Si;
        for (size_t ii = 0; ii < temperatures.size(); ++ii) {
            const int& t = temperatures[ii];
            while (!Si.empty() && t > temperatures[Si.back()]) {
                temperatures[Si.back()] = ii - Si.back();
                // cout << ii << ":" << Si.back() << "->" << temperatures[Si.back()] << endl;
                Si.pop_back();
            }
            Si.push_back(ii);
            // cout << ii << ":" << Si.back() << endl;
        }
        for (int& c: Si) temperatures[c] = 0;
        return temperatures;
    }
};

class Solution {
    /** 739. Daily Temperatures
     * https://leetcode.com/problems/daily-temperatures/
     */
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> Si;
        vector<int> res(temperatures.size(), 0);
        for (int i = temperatures.size() - 1; i >= 0; --i) {
            const int& t = temperatures[i];
            while (!Si.empty() && t >= temperatures[Si.back()]) {
                Si.pop_back();
            }
            if (!Si.empty()) res[i] = Si.back() - i;
            Si.push_back(i);
        }
        return res;
    }
};