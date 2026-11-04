class RecentCounterVector {
    /** 933. Number of Recent Calls
     * https://leetcode.com/problems/number-of-recent-calls/
     */
private:
    vector<int> calls;
    size_t cfi;

public:
    RecentCounter() {
        calls.reserve(10000);
        cfi = 0;
    }
    
    int ping(int t) {
        calls.push_back(t);
        while (3000 < t - calls[cfi]) ++cfi;
        return calls.size() - cfi;
    }
};

class RecentCounter {
    /** 933. Number of Recent Calls
     * https://leetcode.com/problems/number-of-recent-calls/
     */
private:
    deque<int> calls;

public:
    RecentCounter() {
    }
    
    int ping(int t) {
        calls.push_back(t);
        while (3000 < t - calls.front()) calls.pop_front();
        return calls.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */