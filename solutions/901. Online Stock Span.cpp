/** #901. Online Stock Span
	https://leetcode.com/problems/online-stock-span/
	Write a class StockSpanner which collects daily price quotes for some stock, and returns the span of that stock's price for the current day.

	The span of the stock's price today is defined as the maximum number of consecutive days (starting from today and going backwards) for which the price of the stock was less than or equal to today's price.

	For example, if the price of a stock over the next 7 days were [100, 80, 60, 70, 60, 75, 85], then the stock spans would be [1, 1, 1, 2, 1, 4, 6].
*/

class Solution {
    stack<int> priceStack, spanStack;
public:
    StockSpanner() {

    }

    int next(int price) {
        int span = 1;
        while (!priceStack.empty() && priceStack.top() <= price) {
            span += spanStack.top();
            priceStack.pop();
            spanStack.pop();
        }
        priceStack.push(price);
        spanStack.push(span);
        return span;
    }
};

class StockSpanner {
    deque<int> priceStack, spanStack;
public:
    StockSpanner() {

    }

    int next(int price) {
        int span = 1;
        int np = priceStack.size();
        while (np >= span && priceStack[np - span] <= price) {
            span += spanStack[np - span];
        }
        priceStack.push_back(price);
        spanStack.push_back(span);
        return span;
    }
};