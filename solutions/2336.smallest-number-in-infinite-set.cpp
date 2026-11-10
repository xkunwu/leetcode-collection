class SmallestInfiniteSet {
    /** 2336. Smallest Number in Infinite Set
     * https://leetcode.com/problems/smallest-number-in-infinite-set/
     */
private:
    vector<int> Q;
public:
    SmallestInfiniteSet() {
        Q.resize(1000);
        iota(Q.begin(), Q.end(), 1);
    }
    
    int popSmallest() {
        pop_heap(Q.begin(), Q.end(), greater<>());
        const int t = Q.back();
        Q.pop_back();
        return t;
    }
    
    void addBack(int num) {
        if (Q.end() != find(Q.begin(), Q.end(), num)) return;
        Q.push_back(num);
        push_heap(Q.begin(), Q.end(), greater<>());
    }
};

class SmallestInfiniteSet {
    /** 2336. Smallest Number in Infinite Set
     * https://leetcode.com/problems/smallest-number-in-infinite-set/
     */
private:
    set<int> Q;
    int min_thresh = 1;
public:
    SmallestInfiniteSet() {
    }
    
    int popSmallest() {
        if (Q.empty()) return min_thresh++;
        const int t = *Q.begin();
        Q.erase(Q.begin());
        return t;
    }
    
    void addBack(int num) {
        if (num < min_thresh) Q.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */