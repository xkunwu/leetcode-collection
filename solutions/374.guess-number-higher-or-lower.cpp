/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
    /** 374. Guess Number Higher or Lower
        https://leetcode.com/problems/guess-number-higher-or-lower
        We are playing the Guess Game. The game is as follows:

        I pick a number from 1 to n. You have to guess which number I picked (the number I picked stays the same throughout the game).

        Every time you guess wrong, I will tell you whether the number I picked is higher or lower than your guess.

        You call a pre-defined API int guess(int num), which returns three possible results:

            -1: Your guess is higher than the number I picked (i.e. num > pick).
            1: Your guess is lower than the number I picked (i.e. num < pick).
            0: your guess is equal to the number I picked (i.e. num == pick).
            
        Return the number that I picked.
     */
private:
    int guessRecursion(const int& l, const int& r)
    {
        if (l >= r) return l;
        const long long sum = ((long long)l + (long long)r) / 2;
        const int mid = (int)sum;
        const int g = guess(mid);
        if (1 == g) {
            return guessRecursion(mid + 1, r);
        } else if (-1 == g) {
            return guessRecursion(l, mid - 1);
        } else {
            return mid;
        }
    }

public:
    int guessNumber(int n) {
        return guessRecursion(1, n);
    }
};
