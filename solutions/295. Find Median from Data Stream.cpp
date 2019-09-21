/** 295. Find Median from Data Stream
	https://leetcode.com/problems/find-median-from-data-stream/
	Median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value. So the median is the mean of the two middle value.

	For example,
		[2,3,4], the median is 3

		[2,3], the median is (2 + 3) / 2 = 2.5

	Design a data structure that supports the following two operations:

		void addNum(int num) - Add a integer number from the data stream to the data structure.
		double findMedian() - Return the median of all elements so far.
*/

class MedianFinder {
    deque<int> sorted;
public:
    /** initialize your data structure here. */
    MedianFinder() {

    }

    void addNum(int num) {
        if (sorted.empty()) sorted.push_back(num);
        else sorted.insert(
            lower_bound(sorted.begin(), sorted.end(), num),
            num
        );
        //for (int i : sorted) cout << sorted[i] << " ";
        //cout << endl;
    }

    double findMedian() {
        size_t nn = sorted.size();
        if (nn & 1) return sorted[nn >> 1];
        else return (sorted[nn >> 1] + sorted[(nn >> 1) - 1]) * 0.5;
    }
};
class MedianFinder {
    priority_queue<int> lo;
    priority_queue<int, deque<int>, greater<int>> hi;
public:
    /** initialize your data structure here. */
    MedianFinder() {

    }

    void addNum(int num) {
        // balance two queues
        lo.push(num);
        hi.push(lo.top());
        lo.pop();
        // make sure hi.size() <= lo.size() <= hi.size() + 1
        if (lo.size() < hi.size()) {
            lo.push(hi.top());
            hi.pop();
        }
    }

    double findMedian() {
        return (lo.size() > hi.size()) ? lo.top() : (lo.top() + hi.top()) * 0.5;
    }
};
class MedianFinder {
    multiset<int> data;
    multiset<int>::iterator itlo, ithi;
public:
    /** initialize your data structure here. */
    MedianFinder() {

    }

    void addNum(int num) {
        const size_t nn = data.size();
        data.insert(num);
        if (0 == nn) {
            itlo = ithi = data.begin();
        } else if (1 & nn) {
            if (num >= *ithi) ++ithi;
            else --itlo;
        } else {
            if (num >= *ithi) ++itlo;
            else if (num <= *itlo)
                // set insert at the end of equal range,
                // so possibly after lower pointer!
                itlo = --ithi;
            else {
                ++itlo; --ithi;
            }
        }
    }

    double findMedian() {
        return (*itlo + *ithi) * 0.5;
    }
};
